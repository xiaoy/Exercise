#include "stdio.h"
#include "string.h"
typedef struct {
    int age;
    int* pFood ;
}Dog;

typedef struct{
    int age;
    char* pName;
}Duck;

int main() {
    Duck duck;
    duck.pName = "Duck";
    duck.age = 10;
    Dog* dog = (Dog*)&duck;
    printf("the char poiner size is:%d\n", sizeof(char*));
    printf("the sizeof duck is:%u\n", sizeof(duck));
    printf("the duck address is:%u\n", (unsigned int)&duck);
    printf("the duck age address is:%u\n", (unsigned int)&duck.age);
    printf("the duck food address is:%u\n", (unsigned int)&duck.pName);
    return 0;
}
