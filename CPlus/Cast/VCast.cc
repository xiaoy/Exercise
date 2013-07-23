#include <iostream>
#include <exception>
using namespace std;
class Base{
    public:
        virtual void Phony() {

        }
};

class Derived : public Base {
    public:
        int a;
};
int main() {
    Base *b = new Base();
    Derived *d = new Derived();

    Base b1;

    try{
        d = dynamic_cast<Derived*>(b);
        if(d==NULL){
            cout<<"Error"<<endl;
        }
    }catch(exception& e) {
        cout<<"exception is :"<<e.what()<<endl;
    }
    return 0;
}
