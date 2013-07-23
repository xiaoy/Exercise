#include <iostream>
#include "stdio.h"
#include <zthread/Thread.h>
#include <zthread/Runnable.h>
using namespace std;
using namespace ZThread;
class Test{
    public:
        Test(){};
        ~Test(){};
        void Print(const char* str) {
            if(str == NULL) {
                return;
            }
            printf("the string you input is %s\n", str);
        }
};
class Counter : public Runnable{
    int count_;
    int id_;
    public:
        Counter(int count, int id = 0) :count_(count), id_(id) {}
        ~Counter(){};
        void run() {
            while(count_-- > 0) {
                    cout<<id_<<":"<<count_<<endl;
            }
        }
};
int main() {
	//cout<<"hello, world"<<endl;
    //Test test;
    //test.Print("Good Program");
    //Counter c(10);
    //c.run();
    try{
        Thread t(new Counter(10));
        cout<<"Wating for Counter off"<<endl;
    }catch(Synchronization_Exception& e) {
        cerr<< e.what()<<endl;
    }
	return 0;
}
