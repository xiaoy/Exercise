#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int main() {
    char block[1024];
    int in, out;

    in = open("file.in", O_RDONLY);
    out = open("file.out",O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
    while(read(in, block, sizeof(block)) == 1)
        write(out, block, sizeof(block));

    exit(0);
}
