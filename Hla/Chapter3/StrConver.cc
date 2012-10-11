#include <iostream>
#include <string>
using namespace std;
template <class T>
void SetPosBitZero(T& t, int bit) {
    int move = 1 << bit;
    int temp = 0xffffffff - move;
    t = t & temp;
}

template <class T>
void SetPosBitOne(T& t, int bit) {
    t = ~t;
    SetPosBitZero(t, bit);
    t = ~t;
}

template <class T>
void PrintBit(const T& t) {
    int size = sizeof(T) * 8;
    string str;
    for(int i = 0; i < size; ++i) {
        int move = 1 << i;
        int num = t & move;
        if(num != 0) {
            str = "1" + str;
            continue;
        }
        str = "0" + str;
    }
    cout<<str<<endl;
}

const string StrToLower(string& str) {
    for(int i = 0; i < str.size(); ++i)
        SetPosBitOne(str[i], 5);
    return str;
}

const string StrToUpper(string& str) {
    for(int i = 0; i < str.size(); ++i) {
        SetPosBitZero(str[i], 5);
    }
    return str;
}
int main() {
    string str;
    while(true) {
        cout<<"input str:";
        cin>>str;
        if(str == "quit") {
            break;
        }
        StrToUpper(str);
        cout<<"output str:"<<str<<endl;
    }
    return 0;
}
