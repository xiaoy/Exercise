// this program is used to test a function use time
#include <stdio.h>
#include <ctime>
using namespace std;

bool is_primer(long x){
    if(x % 2 == 0){
        return false;
    }

    for(long i = 3; i < x; ++i){
        if(x % i == 0){
            return false;
        }
    }

    return true;
}

int find_primer_in_range(long x){
    long max_primer = 0;
    for(long i = 2; i < x; ++i){
        if(is_primer(i)){
            max_primer = i;
        }
    }

    return max_primer;
}

void test_it_1(long x){
    int now = time(nullptr);
    bool ret = is_primer(x);
    int useTime = time(nullptr) - now;

    printf("use the time %d\n", useTime);
    printf("It is %d the %ld is primer\n", ret, x);
}

void test_it_2(long x){
    int now = time(nullptr);
    long max_primer = find_primer_in_range(x);
    int useTime = time(nullptr) - now;

    printf("use the time %d\n", useTime);
    printf("the max primer in range:%ld is:%ld\n", x, max_primer);
}
int main(){
    long x = 11341;
    test_it_1(x);
    test_it_2(x);

    x = 111111;
    test_it_1(x);
    test_it_2(x);
}
