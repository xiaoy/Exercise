#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

void Rotate(void* front, void* end, void* middle) {
    int front_length = (char*)middle - (char*)front;
    int end_length = (char*)end - (char*)middle;
    assert(front_length || end_length);
    middle = (char*)middle + 1;
    void* temp = malloc(front_length);
    memcpy(temp, front, front_length);
    memcpy(front, middle, front_length);
    memcpy(middle,temp, end_length);
    free(temp);
}

void Rotate2(void* front, void* end, void* middle) {
    int front_length = (char*)middle - (char*)front;
    int end_length = (char*)end - (char*)middle;
    assert(front_length || end_length);
    middle = (char*)middle + 1;
    void* temp = malloc(front_length);
    memcpy(temp, front, front_length);
    memmove(front, middle, front_length);
    memmove(middle,temp, end_length);
    free(temp);
}
int main() {
    char str[6] = {'a', 'b', 'c', 'd', 'e', 'f'};
    //Rotate(str, str + 4, str+2);
    Rotate2(str, str + 4, str+2);
    int i = 0;
    for(; i< 6; ++i) {
        printf("%c", str[i]);
    }
    printf("\n");
    return 0;
}
