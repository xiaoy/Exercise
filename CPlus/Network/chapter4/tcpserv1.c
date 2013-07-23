#include "unp.h"

int
main(int argc, char** argv) {
    int                 saddr_len, caddr_len;
    int                 serv_fd, cli_fd;
    struct sockaddr_in  serv_addr, cli_addr;
    pid_t               pid;

    bzero(&serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(SERV_PORT);
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    serv_fd = Socket(AF_INET, SOCK_STREAM, 0);

    Bind(serv_fd, (SA*)&serv_addr, sizeof(serv_addr));

    Listen(serv_fd, LISTENQ);

    for(; ;) {
        caddr_len = sizeof(cli_addr);
        cli_fd = Accept(serv_fd, (SA*)&cli_addr, &caddr_len);
        if(cli_fd <= 0)
            continue;
        if((pid == Fork()) == 0) {
            str_echo(cli_fd);
            close(serv_fd);
            exit(0);
        }
        close(cli_fd);
    }

}
