#include <iostream>
using namespace std;
class Test{
    public:
        Test();
        ~Test();
        Test& GetTest() {
            return *this;
        }
        const Test& GetConstTest(){
            return *this;
        }

        const Test& operator=(const Test& other) {
            this->value_ = other.value_;
            return *this;
        }

        int ChangeValue(int value) const {
            //value_ = value;   error: value_ is read only
            return value_;
        }
    private:
        int value_;
};
int main() {
    Test test;
    test.GetTest() = test;
    //test.GetConstTest() = test; //error can't assignment to return value
    return 0;
}
