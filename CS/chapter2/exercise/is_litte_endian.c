#include <stdio.h>

int is_little_endian(){
    int a = 1;
    return (a >> 1) == 0 ? 1 : 0;
}


int main(){
    printf("the machine is %s\n", is_little_endian() ? "little endian" : "big endian");
    return 0;
}
