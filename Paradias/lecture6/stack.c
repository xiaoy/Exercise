#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef struct {
    int *array;
    int pos;
    int length;
    int count;
}Stack;

void StackPush(Stack* s, int num) {
    if(s->pos == s->length) {
        s->length *= 2;
        s->array = realloc(s->array,s->length * sizeof(int));
        assert(s->array != NULL);
    }
    s->array[s->pos] = num;
    s->pos += 1;
    s->count += 1;
}

void StackPop(Stack* s) {
    s->count -= 1;
    s->pos -= 1;
}
void NewStack(Stack* s) {
    s->array = (int*)malloc(4 * sizeof(int));
    assert(s->array != NULL);
    s->pos = 0;
    s->length = 4;
    s->count = 0;
}

void FreeStack(Stack* s) {
    free(s->array);
}
int main() {
    int i = 0;
    Stack s;
    NewStack(&s);
    for(i = 0; i < 10; ++i) {
        StackPush(&s, i);
    }

    for(i = 0; i < s.count; ++i) {
        printf("the push num is:%d\n", s.array[i]);
    }
    FreeStack(&s);
    return 0;
}

