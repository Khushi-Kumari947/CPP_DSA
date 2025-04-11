#include<iostream>
using namespace std;

class complex;

class calculator
{
    public:
      int add(int a ,int b)
      {
        return (a+b);
      }
      int sumRealComplex(complex,complex);
      int sumcompComplex(complex,complex);
};

class complex
{
     int a,b;
     //Individually declaring function as friend 
    //  friend int calculator :: sumRealComplex(complex,complex);
    //  friend int calculator :: sumcompComplex(complex,complex);
    //  ALTER: declare entire clas function as friend ;
    friend class calculator;
     public:
        void setNumber(int n1,int n2)
        {
            a=n1;
            b=n2;
        }
        // void printNumber()
        // {
        //     cout<<"your number is "<<a<<" + "<<b<<"i"<<endl;
        // }
};

int calculator::sumRealComplex(complex k1 , complex k2)
{
    return (k1.a+k2.a);
}
int calculator::sumcompComplex(complex k1 , complex k2)
{
    return (k1.b+k2.b);
}


int main(){
    complex c1,c2;
    c1.setNumber(1,4);
    c2.setNumber(3,4);
    calculator calc;
    int res=calc.sumRealComplex(c1,c2);
    cout<<"The sum of real part of entered complex number is:"<<res<<endl;
    int res1=calc.sumcompComplex(c1,c2);
    cout<<"The sum of complex part of entered complex number is:"<<res1<<endl;
    return 0;
}