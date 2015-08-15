/****************************************************************************************************
author:wulongfei
blog:blog.csdn.net/hackmind
email:zgwulongfei@gmali.com
why:Just find some fun and exercise my programming
****************************************************************************************************/

#include <stdio.h>

typedef unsigned int uint;
typedef unsigned char uchar;

uint replace_byte(uint x, uchar b, int i){
    int sz = sizeof(x);
    if(i >= sz || i < 0){
        return x;
    }

    int x_shift = i << 3;
    uint x_replace = ((uint)b << x_shift);
    uint x_dis = 0xff << x_shift;

    return ((x & (~x_dis)) + x_replace);
}

void test(uint x, uchar b, int i){
    printf("%x replace at %d by %x, ret:%x\n", x, i, b, replace_byte(x, b, i));
}

int main(){
    for(int i = 0; i < sizeof(uint); ++i)
        test(0x12345678, 0xAB, i);

    return 0;
}
