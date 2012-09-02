#include <iostream>
using namespace std;

int main() {
    int a[] = {1,2,3,4,5,6,7,8};
    cout<<"ptr-a[0]:"<<&a[1]<<endl;
    cout<<"ptr-a[4]:"<<&a[4]<<endl;
    cout<<"sizeof a:"<<sizeof(a)<<endl;
}
