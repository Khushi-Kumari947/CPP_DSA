#include<iostream>
using namespace std;
int count(int a)
{
    int count=0;
    while(a!=0)
    {
        if(a&1==1)
        {
            count++;
        }
        a=a>>1;
    }
    return count;
}
int ap(int n)
{
    return n*3+7;
}

int setBits(int a, int b)
{
    int countA=0,countB=0;
    countA=count(a);
    countB=count(b);
    return countA+countB;
}
int fibo(int num)
{
    int a=0,b=1,fib;
    for (int  i = 0; i < num; i++)
    {
        fib=a+b;
        a=b;
        b=fib;
    }
    return fib;
    
}
int main(){
    
    int n1,n2,n3,n4;
    cin>>n1>>n2>>n3>>n4;
    cout<<ap(n1)<<endl;
    cout<<setBits(n2,n3)<<endl;
    cout<<fibo(n4)<<endl;
    return 0;
}