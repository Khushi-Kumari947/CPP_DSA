#include<iostream>
using namespace std;

int expo(int a ,int b)
{
    int ans;
    b=-b;
    if(b==0)
    {
        return 1;
    }
    else if(b==1)
    {
        return (1/a);
    }
    else{
        if(b%2==0)
        {
             ans=expo(a,b/2);
             return (1/ans)*(1/ans);
        }
        else{
            ans=expo(a,(b-1)/2);
            return (1/a)*(1/ans)*(1/ans);
        }
    }
}

int main()
{
    int x,y;
    cout<<"enter base and exponent"<<endl;
    cin>>x;
    cin>>y;
    int r=expo(x,y);
    cout<<r<<endl;
}