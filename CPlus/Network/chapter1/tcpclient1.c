#include "unp.h"

int
main(int argc, char** argv) {
    int                 fd, n;
    char                buff[MAXLINE];
    struct sockaddr_in  addr;

    fd = Socket(AF_INET, SOCK_STREAM, 0);
    bzero(&addr, sizeof(addr));
    addr.sin_family         = AF_INET;
    addr.sin_port           = htons(13);
    if(inet_pton(AF_INET, argv[1], &addr.sin_addr) <= 0)
        err_quit("inet_pton error for %s", argv[1]);

    if(connect(fd, (SA*)&addr, sizeof(addr)) < 0)
        err_sys("connect error");
    else
        printf("connect success\n");

    char input[MAXLINE];
    for( ; ; ) {
        printf("---------------------\n");
        fgets(input, MAXLINE, stdin);
        Write(fd, input, strlen(input));
        bzero(buff, strlen(buff));
        n = Read(fd, buff, MAXLINE);
        if(n < 0) {
            continue;
        }
        buff[n] = 0;
        fputs(buff, stdout);
    }

    exit(0);
}
