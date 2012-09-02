#include <iostream>

using namespace std;

int main() {
    float f = 6.0f;

    int i =  *(int*)(&f);
//    i = i>>23;
    cout<<i<<endl;
}
