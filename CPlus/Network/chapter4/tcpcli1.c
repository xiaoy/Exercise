#include "unp.h"

int
main(int argc, char** argv) {
    int                 sock_fd;
    struct sockaddr_in  serv_addr;

    sock_fd= Socket(AF_INET, SOCK_STREAM, 0);

    bzero(&serv_addr, sizeof(serv_addr));

    serv_addr.sin_port = htons(SERV_PORT);
    serv_addr.sin_family = AF_INET;
    Inet_pton(AF_INET, argv[1], &serv_addr.sin_addr);

    Connect(sock_fd, &serv_addr, sizeof(serv_addr));
    str_cli(stdin, sock_fd);
    exit(0);
}
