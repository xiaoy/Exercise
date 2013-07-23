#include "stdio.h"

typedef struct{
    int color;
    int size;
    char* name;
} Apple;

typedef struct{
    int color;
    int size;
    char* name;
} Orange;
int main() {
    Apple a;
    a.color = 0x00aabb;
    a.size = 10;
    a.name = "apple";
    Orange* o = &a;
    printf("the orange name is:%s\n", o->name);
    return 0;
}
