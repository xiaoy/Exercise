#include <iostream>
using namespace std;
class Base {
    public:
        int x;
};

class Derived : public Base {
    public:
        int y;
        int z;
};
int main() {
    Base* b = new Base();
    b->x = 10;

    Derived* d = new Derived();
    d->x = 20;
    d->y = 30;
    d->z = 40;

    Base *b1 = dynamic_cast<Base*>(d);

   // Derived* d1 = dynamic_cast<Base*>(b);

    cout<<"b1->x is:"<<b1->x<<endl;
    cout<<"b1->x address is:"<<&b1->x<<endl;
    cout<<"d->x address is:"<<&d->x<<endl;
    cout<<"d->y address is:"<<&d->y<<endl;
    cout<<"d->z address is:"<<&d->z<<endl;
}
