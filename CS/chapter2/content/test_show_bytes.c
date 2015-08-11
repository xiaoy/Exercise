#include "show_bytes.h"
#include <string.h>

void test_show_bytes_0(int val){
    int ival = val;
    float fval = (float)ival;
    int* pval = &ival;

    show_int(ival);
    show_float(fval);
    show_pointer(pval);
}

void test_show_bytes_1(){
    int val = 0x87654321;
    byte_pointer valp = (byte_pointer)&val;
    show_bytes(valp, 1);
    show_bytes(valp, 2);
    show_bytes(valp, 3);
}

void test_show_bytes_2(){
    const char* s = "abcdef";
    show_bytes((byte_pointer)s, strlen(s));
}

int main(){
    //test_show_bytes_0(12345);

    //test_show_bytes_1();

    test_show_bytes_2();
    return 0;
}
