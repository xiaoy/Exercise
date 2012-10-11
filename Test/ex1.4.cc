#include <iostream>
using namespace std;
#define PI 3.14
#define Log(str) cout<<str<<endl
#define Max(a, b) a > b ? a : b

int main() {
    int a = 12;
    int b = 5;
    int max = Max(a, b);
    Log(PI);
    Log(max);
    Log("hello, world");
    return 0;
}
