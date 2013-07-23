#include "unp.h"

int
main(int argc, char** agrv) {
    int                 listenfd, connfd, n;
    socklen_t           len;
    struct sockaddr_in  servaddr, cliaddr;
    char                buff[MAXLINE], addr[sizeof(cliaddr) + 1];

    listenfd = Socket(AF_INET, SOCK_STREAM, 0);

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family         = AF_INET;
    servaddr.sin_addr.s_addr    = htonl(INADDR_ANY);
    servaddr.sin_port           = htons(13);

    Bind(listenfd, (SA*)&servaddr, sizeof(servaddr));

    Listen(listenfd, LISTENQ);

    len = sizeof(cliaddr);
    connfd = Accept(listenfd, (SA*)&cliaddr, &len);
    char* pcliaddr = Inet_ntop(AF_INET, &cliaddr.sin_addr, addr, sizeof(addr));
    printf("connection from %s, port %d\n",
        pcliaddr,
        ntohs(cliaddr.sin_port));

    char line[MAXLINE * 2] ={0};
    for( ; ; ) {
        bzero(line, strlen(line));
        sprintf(line, "%s say:", pcliaddr);
        bzero(buff, strlen(buff));
        Read(connfd, buff, MAXLINE);
        strncat(line, buff, strlen(buff));
        Write(connfd, line, strlen(line));
    }
    return 0;
}
