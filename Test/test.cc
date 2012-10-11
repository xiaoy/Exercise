#include <iostream>
using namespace std;
class Point {
    public:
        Point(int x, int y) : x_(x), y_(y) {

        }
        virtual ~Point() {
            cout<<"Des Point\n";
        }
        virtual void PrintX() {
            cout<<"Point::x is:"<<x_<<endl;
        }

        virtual void PrintY() {
            cout<<"Point::y is:"<<y_<<endl;
        }
    private:
        int x_;
        int y_;
};

class Point3d : public Point {
    public:
        Point3d(int x, int y, int z) : Point(x,y), z_(z) {

        }
        virtual ~Point3d() {
            cout<<"Des Point3d\n";
        }

        virtual void PrintZ() {
            cout<<"Point3d::Print z:"<<z_<<endl;
        }
    private:
        int z_;
};

int Print() {
    cout<<"test"<<endl;
}
int main() {
    typedef void (*Fun)(void);
    Fun func;
    Point3d *ptr = new Point3d(1, 2, 3);
    //func = *(Fun*)(*(Fun*)ptr);
   // func = (Fun)(*(long*)(*(long*)ptr));
    long temp = (*(long*)ptr);
    func = (Fun)(*(long*)temp);
    func();
    //delete ptr;
    return 0;
}
