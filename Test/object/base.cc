#include <iostream>
using namespace std;

class Point2d {
    public:
        int x_;
        int y_;
        int z_;
};

class Point3d :virtual public Point2d {
    public:
        int z_;
        Point3d* GetThis(){
            return this;
        }
};
int main() {
    Point3d* ptr3 = new Point3d;
    ptr3->z_ = 3;
    Point2d* ptr2 = ptr3;
    ptr2->z_ = 2;
    printf("ptr2 is:%p\n", ptr2);
    printf("ptr3 is:%p\n", ptr3);
    printf("ptr3_x is:%p\n", &(ptr3->x_));
    printf("ptr3_y is:%p\n", &(ptr3->y_));
    printf("ptr3_z is:%p\n", &(ptr3->z_));
    printf("ptr2_x is:%p\n", &(ptr2->x_));
    printf("ptr2_y is:%p\n", &(ptr2->y_));
    printf("ptr2_z is:%p\n", &(ptr2->z_));
    printf("ptr2_z is:%d\n", (ptr2->z_));
    printf("ptr3_z is:%d\n", (ptr3->z_));
    printf("pt3 this is:%p\n", ptr3->GetThis());
    printf("pt2 this is:%p\n", ptr3->GetThis());
    printf("size of Point3d is:%lu\n", sizeof(Point3d));
    printf("size of Point2d is:%lu\n", sizeof(Point2d));
}
