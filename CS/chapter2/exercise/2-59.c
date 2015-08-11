#include <stdio.h>

int main(){
    int x = 0x89ABCDEF;
    int y = 0x76543210;

    int end_x = x & 0xff;
    int start_y = (y & (~0xff));

    printf("after %x end replace %x ret is:%x\n", x, y, (end_x + start_y));
    return 0;
}
