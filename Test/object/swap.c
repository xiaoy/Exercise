#include <stdio.h>
#include <string.h>
void Swap(void* vp1, void* vp2, int size) {
    char temp[size];
    memcpy(temp, vp1,size);
    memcpy(vp1, vp2, size);
    memcpy(vp2, temp, size);
    printf("the vp1 is:%p\n", vp1);
    printf("the vp2 is:%p\n", vp2);
    printf("the temp is:%p\n", temp);
}
int main() {
//    int a = 20;
//    int b = 30;
//    printf("before swap a: %d, b:%d\n", a, b);
//    Swap(&a, &b, 4);
//    printf("after swap a: %d, b:%d\n", a, b);
//    float fa = 20.333f;
//    float fb = 49.2323f;
//    Swap(&fa, &fb, sizeof(fa));
//    printf("after swap fa: %f, fb:%f\n", fa, fb);
    char* husband = "lfwu";
    char* wife = "yyguo";
    int i =0;
    for(; i < strlen(husband); i++) {
        printf("%c", *(husband + i));
    }
    printf("\n");
    Swap(&husband, &wife, 4);
    printf("the husband point is%p\n", husband);
    printf("the &husband point is%p\n", &husband);
    printf("the wife point is%p\n", wife);
    printf("the &wife point is%p\n", &wife);
    printf("the ret husband is:%s\twife is:%s\n", husband, wife);
}
