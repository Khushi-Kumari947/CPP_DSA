#include<iostream>
using namespace std;

class complex
{
     int a,b;
     public:
        void setNumber(int n1,int n2)
        {
            a=n1;
            b=n2;
        }
        friend complex  sumComplex(complex o1,complex o2);
        void printNumber()
        {
            cout<<"your number is "<<a<<" + "<<b<<"i"<<endl;
        }
};

complex sumComplex(complex k1,complex k2)
{
    complex result;
    result.setNumber(k1.a+k2.a,k1.b+k2.b);
    return result;
}

int main(){
    complex c1,c2,c3;
    c1.setNumber(1,4);
    c1.printNumber();
    c2.setNumber(3,4);
    c2.printNumber();
    c3=sumComplex(c1,c2);
    c3.printNumber();
    return 0;
}