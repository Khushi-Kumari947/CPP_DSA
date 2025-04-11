#include<iostream>
using namespace std;

class demo
{
    int a;
    friend class D;
    public:
      demo(int y)
      {
        a=y;
      }
      void print()
      {
        cout<<a<<endl;
      }
       
};

class D
{
    int b;
    public:
    D(int y)
      {
        b=y;
      }
    int sum(demo D1)
    {
        cout<<"sum = "<<b+D1.a<<endl;
    }
};

int main(){
    
    demo Demo1(34);
    D D2(23);
    D2.sum(Demo1);

    return 0;
}