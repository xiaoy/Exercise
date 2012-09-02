#include <iostream>
class test {
    public:
        test(){};
        ~test(){};
        int a;
        std::string str_;
        const test& operator=(const test& rhs){ this->a = rhs.a;}
        friend bool operator==(std::ostream& out, const test& rhs2){
            out<<rhs2.str_;
        }
        void print(const char* str) {
            std::cout<<str;
        }
};
int main() {
    test test1;
    test1.str_ = "nima\n";
    std::cout==test1;
    return 0;
}
