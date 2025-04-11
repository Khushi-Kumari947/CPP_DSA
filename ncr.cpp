#include<iostream>
using namespace std;

int fact (int num)
{
    int fact=1;
    for (int i = 1; i <= num; i++)
    {
        fact=fact*i;
    }
    // cout<<fact;
    return fact;  
}
int ncr(int n ,int r)
{
    int nem=fact(n);
    int denm=(fact(r)*fact(n-r));
    return nem/denm;
}
int main(){
    cout<<"here"<<endl;
    cout<< ncr(5,3)<<endl;
    cout<<"here2";
    return 0;
}