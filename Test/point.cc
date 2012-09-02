#include <iostream>

using namespace std;

class Point{
    public:
        Point() {}
        Point(int x, int y) : x_(x), y_(y) {}
        virtual ~Point() {}
        void PrintPoint();
        virtual void DrawPoint();
    public:
        int x_;
        int y_;
};

void Point::PrintPoint() {
    cout<<"the Point PrintPoint call\n";
}

void Point::DrawPoint() {
    cout<<"the Point DrawPoint call\n";
}

class Point3d : public Point {
    public:
        Point3d() {}
        Point3d(int x, int y, int z) : Point(x , y), z_(z), x_(++x), y_(++y) {}
        virtual ~Point3d() {}
        void PrintPoint();
        virtual void DrawPoint();
    public:
        int x_;
        int y_;
        int z_;
};

void Point3d::PrintPoint() {
    cout<<"the point3d PrintPoint call\n";
}

void Point3d::DrawPoint() {
    cout<<"the Point3d DrawPoint call\n";
}

int main() {
    Point3d p3;
    Point3d *ptr3;
    Point *p = new Point3d(1, 2, 3);
    Point3d *ptr = new Point3d(1, 2, 3);
    //cout<<p->z_<<endl;
    ptr3 = &p3;
    p3.DrawPoint();
    ptr3->PrintPoint();
    ptr3->DrawPoint();
    p->PrintPoint();
    p->DrawPoint();
    cout<<p->x_<<"\t"<<p->y_<<endl;
    cout<<ptr->x_<<"\t"<<ptr->y_<<endl;
    delete p;
    return 0;
}
