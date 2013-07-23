#include <iostream>
#include <typeinfo>
using namespace std;
class Foo{
    public:
        int x;
        }
};
int main() {
    int a = 2;
    Foo* f = new Foo();
    f->x = 100;
    cout<<"the Foo type is:"<<typeid(f).name()<<endl;
    cout<<"the a type is:"<<typeid(a).name()<<endl;
    return 0;
}
