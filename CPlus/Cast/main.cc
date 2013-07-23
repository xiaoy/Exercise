#include <iostream>
#include <string>
using namespace std;

typedef struct{
    char* name;
    char* GetName() {
        return name;
    }
}Apple;

typedef struct{
    char* name;
    char* GetName() {
        return name;
    }
}Orange;

int Print() {
    return 0;
}

int Print(char* str) {
    return 0;
}

int main() {
    Apple *a = new Apple();
    string str = "Apple";
    a->name = (char*)str.c_str();
    Orange *O = (Orange*)(a);

    cout<<O->name<<endl;
    return 0;
}
