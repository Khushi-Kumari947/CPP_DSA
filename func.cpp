#include<iostream>
using namespace std;

int sum(int a,int b)
{
    int sum;
    sum=a+b;
    return sum;
}
void swapRef(int &a,int &b)
{
    int temp=a;
    a=b;
    b=temp;
}



int main(){
    int num1,num2;
    cout<<"Enter first number:"<<endl;
    cin>>num1;
    cout<<"Enter second number:"<<endl;
    cin>>num2;
    cout<<"The sum is:"<<sum(num1,num2)<<endl;
    swapRef(num1,num2);
    cout<<"The value of num1 and num2 after swapping is:"<<num1<<" "<<num2;
    return 0;
}