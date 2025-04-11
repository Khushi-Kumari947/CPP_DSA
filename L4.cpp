#include <iostream>
using namespace std;

class Shape
{
    private:

       float radius;
       float width;
       float length;
       float base;
       float height;
    public:
       Shape()
       {
        radius=0;
        width=0;
        length=0;
        height=0;
        base=0;
       }

       Shape(float rad)
       {
         radius=rad;
         cout<<"Area of the circle with radius = "<<radius<<" is "<<3.14*radius*radius<<endl;
       }

       Shape(float len, float bre)
       {
        length=len;
        width=bre;
        cout<<"Area of the Rectangle with Length = "<<length<<" and Breath = "<<width<<length*width<<endl;
       }
       Shape(float hei, float bas)
       {
        height=hei;
        base=bas;
        cout<<"Area of the Triangle with height = "<<height<<" and Base = "<<base<<0.5*height*base<<endl;
       }

};

int main()
{
    Shape Circle(10),Rectangle(45,25),Triangle(10,20);
}