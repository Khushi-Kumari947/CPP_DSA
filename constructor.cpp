#include<iostream>
using namespace std;

class complex
{
    int a,b;
    public:
       complex(void);
        void printNumber(void)
       {
            cout<<"The compplex number is "<<a<<" + "<<b<<"i"<<endl;
       }
};

complex::complex(void)
{
    a=0;
    b=0;
}

int main(){
    complex c1,c3,c2;
    c1.printNumber();
    c2.printNumber();
    c3.printNumber();
    return 0;
}