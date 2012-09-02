#include <iostream>
#include "Random.h"
using namespace std;
#define ARRAY_LENGTH 10
bool Search(int key, int *base, int length) {
    for(int i =0; i < length; ++i) {
        if(key == *base++) {
            return true;
        }
    }
    return false;
}

void* LSearch(void* key, void* base, int size, int length, bool (*cmp)(void*, void*)) {
    printf("the base is :");
    for(int i =0; i < length; ++i) {
        void* ptrAddr = (char*)base + size * i;
        if(cmp(key, ptrAddr)==0) {
            return key;
        }
        if(memcmp(key, ptrAddr, size) == 0) {
            return key;
        }
        printf("%d\t", *(int*)ptrAddr);
    }
    printf("\ncan't find the num\n");
    return NULL;
}
bool Compare(void* a, void* b) {
    return *(int*)a - *(int*)b;
}
int main() {
    int array[ARRAY_LENGTH];
    printf("the num is:");
    for(int i = 0; i < ARRAY_LENGTH; ++i) {
        array[i] = RandomRange(0, 100);
        printf("%d\t", array[i]);
    }
    int key;
    printf("\nInput the num you want to search:");
    scanf("%d", &key);
    if(LSearch(&key, array, 4, ARRAY_LENGTH, Compare)) {
        printf("find it:%d\n", key);
    }
    else {
        printf("not exsit\n");
    }
    return 0;
}
