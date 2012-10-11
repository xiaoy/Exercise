#include <iostream>
using namespace std;
int main() {
    const int ci = 2;
    cout<<"the addr of ci is:"<<(&ci)<<endl;
    int *p = const_cast<int*>(&ci);
    cout<<"the addr of p is:"<<p<<endl;
    *p = 5;
    cout<<"the value of ci is:"<<ci<<endl;
    cout<<"the value of p is:"<<(*p)<<endl;
    return 0;
}
