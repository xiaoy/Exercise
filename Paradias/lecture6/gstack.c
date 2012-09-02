#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#define BASE_LENGTH 4
typedef struct{
    void* elements;
    int elementSize;
    int allocSize;
    int pos;
}Stack;

void StackNew(Stack* s, int size) {
    s->elementSize = size;
    s->pos = 0;
    s->allocSize = size * BASE_LENGTH;
    s->elements = malloc(s->allocSize);
    assert(s->elements != NULL);
}

void StackPush(Stack* s, void* element) {
    if(s->pos == s->allocSize) {
        s->allocSize *= 2;
        s->elements = realloc(s->elements, s->allocSize);
        assert(s->elements);
    }
    void* next = (char*)s->elements + s->pos;
    memcpy(next, element, s->elementSize);
    s->pos += s->elementSize;
}

void StackPop(Stack* s) {
    if(s->pos == 0) {
        printf("Error: Stack is null\n");
        return;
    }
    s->pos -= s->elementSize;
}

void StackFree(Stack* s) {
    free(s->elements);
}
int main() {
    Stack s;
    int i = 0;
    //double d = 0.233;
    char *friends[] = {"aa", "bb", "cc"};
    StackNew(&s, sizeof(char*));

    for(i = 0; i < 3; ++i){
        StackPush(&s, &friends[i]);
    }

    for(i = 0; i < 3; ++i) {
        printf("the friends is:%s\n", *((char**)s.elements + i));
    }
    //StackNew(&s, sizeof(double));
    ///*-------Test stack push-----*/
    //for(i = 0; i < 10; ++i) {
    //    d = d * 2;
    //    StackPush(&s, &d);
    //}

    //double *arr = s.elements;
    //printf("\nafter push the num is:");
    //for(i = 0; i < s.pos/sizeof(double); ++i) {
    //    printf("%f\n", arr[i]);
    //}

    ///*-------Test stack pop------*/
    //StackPop(&s);
    //printf("\nafter pop the num is:");
    //for(i = 0; i < s.pos/sizeof(double); ++i) {
    //   printf("%f\n", arr[i]);
    //}

    //StackFree(&s);
    return 0;
}
