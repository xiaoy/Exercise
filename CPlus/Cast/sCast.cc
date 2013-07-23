#include <iostream>
#include <exception>

using namespace std;
class Base {
    public:
        int x;
};

class Derived : public Base{
    public:
        int y;
        int z;
};
int main() {
    Base* b = new Base();
    b->x = 10;

    Derived *d = new Derived();
    d->y = 20;
    d->z = 30;

    try{
        d = static_cast<Derived*>(b);
        cout<<"the d->x is:"<<d->x<<endl;
        cout<<"the d->y is:"<<d->y<<endl;
        cout<<"the d->z is:"<<d->z<<endl;
    }catch(exception& e){
        cout<<"the exception is:"<<e.what()<<endl;
    }
}
