#include <stdio.h>

int is_equal(int a, int b){
    int c = a ^ b;
    return !(c & a);
}
int main(){
    printf("%d\n", is_equal(1, 2));
    printf("%d\n", is_equal(2, 2));
    return 0;
}
