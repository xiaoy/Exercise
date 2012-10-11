#include <iostream>
#include <string>
using namespace std;
int b = 10;
int& GetConstNum() {
    return b;
}
class Test {
    public:
        Test():a_(2),b_(3){
        }
        int a_;
        const int b_;
        static const float f_ = 1.3f;
        static const int c_ = 4;
        string str_;
    public:
        const int GetConstNum() {
            return a_;
        }
        const int GetConstB() {
            return b_;
        }
        const Test& operator=(const Test& test) {
        }
        // three means
        // 1.pass the object reference
        // 2.the reference can't be changed
        // 3.the return value can't assignment,this can forbidden '='
        const Test& operator*(const Test& test) {
            this->a_ = this->a_ * test.a_;
            return *this;
        }

        const char& operator[](const int pos) const{
            return str_[pos];
        }
        char& operator[](const int pos) {
            return const_cast<char&>(static_cast<Test&>(*this)[pos]);
        }
    private:
        const Test& operator==(const Test&); // this function can forbidden call '==' operator
};

int main() {
    const int num = 2; // this must be initiate
    int num2 = 2;
    const int &r_num = num;
    const int *p_num1 = &num; // this can be not initiate
    int *const p_num2 = &num2; // the p_num2 can't changed
    int const *p_num4 = &num2; // the *p_num4 can't changed
    const int * const p_num3 = &num;

    int a;
    GetConstNum()++;
    cout<<b<<endl;
    Test test;
    Test test1;
    test = test * test1;
    cout<<test.a_<<endl;
    cout<<Test::f_<<endl;
    cout<<test.str_<<endl;
    return 0;
}

// two problems
// static const string
// call const operator from no const operator
