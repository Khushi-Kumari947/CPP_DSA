#include<iostream>
using namespace std;

class complex
{
    private:
       int a,b;
    public:
       
       complex()
       {
             a=0;
             b=0;
       }

       void setData(int x,int y)
       {
        a=x;
        b=y;
       }

       void getData()
       {
        cout<<"a = "<<a<<" b = "<<b<<endl;
       }

       complex operator +(complex c)
       {
        complex temp ;
        temp.a=a+c.a;
        temp.b=b+c.b;
        return temp;

       }
};

int main(){
    complex c1,c2,c3;
    c1.setData(3,5);
    c2.setData(4,0);
    c3=c1+c2;
    // c3=c1.operator+(c2);
    c3.getData();


    return 0;
}