#include <iostream>
using namespace std;
class Point {
    public:
        virtual ~Point() {
            cout<<"the this point is:"<<endl;
            cout<<"Des Point\n";
        }
};

class Point3d : public Point {
    public:
        virtual ~Point3d() {
            cout<<"Des Point3d\n";
        }
};

int main() {
    Point *ptr = new Point3d();
    delete ptr;
    return 0;
}
