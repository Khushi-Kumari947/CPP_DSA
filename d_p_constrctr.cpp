#include <iostream>
using namespace std;
#include <cmath>

class point
{
    int a, b;
    friend class D ; //void distance(point x, point y);
public:
    point(int, int);
    void printNumber(void)
    {
        cout << "The point is (" << a << ", " << b << ")" << endl;
    }
};

point::point(int x, int y)
{
    a = x;
    b = y;
}

class D
{
public:
    void distance(point p1, point p2)
    {
        float r;
        r = sqrt(pow((p1.a - p2.a), 2) + pow((p1.b - p2.b), 2));
        cout<<r<<endl;
    }
};

int main()
{
    point a(4, 6);         // implicit call
    point b = point(5, 7); // explicit call
    a.printNumber();
    b.printNumber();
    D d1;
    d1.distance(a,b);
    // c2.printNumber();
    // c3.printNumber();
    // int r = distance(a, b);
    // cout << r << endl;
    return 0;
}