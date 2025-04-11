#include<iostream>
using namespace std;

class SUM
{
    public:
      void sum(int a,int b)
      {
         cout<<"The sum of "<<a<<"and "<<b<<"is"<<a+b<<endl;
      }
};

class sum_ref:public SUM
{
    public:
    void sum(int &a,int &b)
      {
         cout<<"The sum of "<<a<<"and "<<b<<"is"<<a+b<<endl;
      }
};


int main(){
    SUM s1;
    sum_ref s2;
    int x,y;
    cout<<"Enter two numbers";
    cin>>x>>y;
    cout<<"sum using pass by value";
    s1.sum(x,y);
    cout<<"sum using pass by reference";
    s2.sum(x,y);
    return 0;
}