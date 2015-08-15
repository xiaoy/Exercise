/****************************************************************************************************
author:wulongfei
blog:blog.csdn.net/hackmind
email:zgwulongfei@gmali.com
why:Just find some fun and exercise my programming
****************************************************************************************************/

#include <stdio.h>

int main(){
    int a = 0;
    int b = ~a;
    int c = 0xff << ((sizeof(int) - 1) << 3);
    int d = 0xff;

    printf("0x%.8x all bit one is %s\n", b, !(~b) ? "true" : "false");
    printf("0x%.8x all bit zero is %s\n", a, !(a) ? "true" : "false");
    printf("0x%.8x all high bit one is %s\n", c, !(c - c) ? "true" : "false");
    printf("0x%.8x all low bit one is %s\n", d, !(d - 0xff) ? "true" : "false");

    return 0;
}
