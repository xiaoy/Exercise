#include <stdint.h>
#include <stdio.h>
uint32_t htonf(float f) {
    uint32_t p;
    uint32_t sign;

    if(p < 0) {sign = 1; f = -f;}
    else {sign = 0;}

    p = (((uint32_t)f)<<16) | (sign<<31);

    p |= (uint32_t)((f- (uint32_t)f) * 65536.0f);

    return p;
}

float ntohf(uint32_t p) {
    float f = (p>>16);
    f += (p & 0xffff)/ 65536.0f;
    if((p>>31) == 0x1){ f = -f;}
    return f;
}

int main() {
    float f= 3.1415926;
    printf("the before float is:%f\n", f);
    uint32_t i = htonf(f);
    printf("the int is:%d\n", i);
    f = ntohf(i);
    printf("hte float is:%f\n", f);
    return 0;
}
