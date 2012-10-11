#include <iostream>
#include "a.h"
using namespace std;
extern int aaa;

const char* GetName() {
    return "wulongfei";
}

void Print() {
    cout<<aaa<<endl;
}
