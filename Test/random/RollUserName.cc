#include <iostream>
#include <string>
#include <ctime>
using namespace std;

static int seed = time(NULL);
int RandomRange(int min, int max) {
    srand(seed);
    seed = rand();
    return (min + (rand())%(max-min));
}
char RollChar() {
     std::string chars(
        "abcdefghijklmnopqrstuvwxyz"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "1234567890"
        "!@#$%^&*()"
        "`~-_=+[{]{\\|;:'\",<.>/? ");
    char ch = chars[RandomRange(0, chars.size())];
    return ch;
}

string RollString(int min, int max) {
    int str_len = RandomRange(min, max);

    string str(str_len, '0');
    for(int i = 0; i < str_len; ++i) {
        str[i] = RollChar();
    }
    return str;

}

int main() {
    int count, min_length, max_length;
    cout<<"the count you want to:\n";
    cin>>count;
    cout<<"the min, and max username length:\n";
    cin>>min_length>>max_length;
    if(min_length > max_length || min_length < 0) {
        cout<<"you stupid boy!!!\n";
        return 1;
    }

    for(int i = 0; i < count; ++i) {
        cout<<"the user name is:\t"<<RollString(min_length, max_length)<<"\tThe pwd:\t"<<RollString(8,10)<<endl;
    }
    return 0;
}
