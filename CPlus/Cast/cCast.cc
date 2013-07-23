#include <iostream>
#include <string.h>
#include <exception>
using namespace std;

int main() {
    const char* str = "hello,world";
    try{
        char* newStr = const_cast<char*>(str);
        string text = static_cast<string>(str);
        cout<<newStr<<endl;
        for(int i =0; i <strlen(newStr) ; ++i) {
            //newStr[i] = 'x';
         }
         cout<<newStr<<endl;
    }catch(exception& e) {
        cout<<"the exception is:"<<e.what()<<endl;
    }
}
