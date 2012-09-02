#include <iostream>
using namespace std;
struct fraction{
    int a;
    int i;
};
int main() {
    fraction pi;
    pi.a = 12;
    pi.i = 22;
    ((fraction*)(&pi.a))->i = 23;
    cout<<pi.i<<endl;
}
