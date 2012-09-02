#include <stdio.h>

struct stack {
    int array[];
    int pos;
    int length;
}stack;

stack* StackNew() {
    stack intStack;
    int size = 4*sizeof(int);
    intStack.array = alloc(size);
    intStack.pos = 0;
    intStack.length = size;
    return &intStack;
}

void StackPush(stack* s, int num) {
    if(s->pos == s->length-1) {
        s->array = realloc(s->length * 2);
    }
    s->array[s->pos] = num;
    s->pos += sizeof(int);
}
int main() {
    int a = 1;
    int i = 0;
    stack* s = StackNew();
    StackPush(s, a);
    printf("the push num is:%d\n", s->array[0]);
    return 0;
}
