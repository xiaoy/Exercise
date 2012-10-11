#include <stdio.h>
void Swap(int* pa, int* pb) {
    *pa = *pa ^ *pb;
    *pb = *pa ^ *pb;
    *pa = *pa ^ *pb;
}

void Swap1(int* pa, int* pb) {
    *pa = *pb + *pa;
    *pb = *pa - *pb;
    *pa = *pa - *pb;
}
int main() {
    int a = 12;
    int b = 15;
    printf("a is:%d\tb is:%d\n", a, b);
    Swap1(&a, &b);
    printf("a is:%d\tb is:%d\n", a, b);
}
