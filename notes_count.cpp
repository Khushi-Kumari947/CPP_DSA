#include<iostream>
using namespace std;

void PrintNumber(int n)
{
    for (int  i = 1; i <= n; i++)
    {
        cout<<i<<endl;
    }
    
}

int main(){
    int num,a,h=0,f=0,t=0,R=0;
    cin>>num;
    a=num;
    cout<<"The number of 100 notes required for "<< a <<" is"<<endl;
    h=num/100;
    cout<<h<<endl;
    num=num-100*h;
    cout<<"The number of 50 notes required for "<< a <<" is"<<endl;
    f=num/50;
    cout<<f<<endl;
    num=num-50*f;
    cout<<"The number of 10 notes required for "<< a <<" is"<<endl;
    t=num/10;
    cout<<t<<endl;
    num=num-10*t;
    cout<<"The number of 1 notes required for"<< a <<"is"<<endl;
    R=num;
    cout<<R<<endl;
    
    int n ;
    cin>>n;
    PrintNumber(n);
    
    return 0;
}