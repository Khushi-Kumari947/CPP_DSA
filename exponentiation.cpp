#include<iostream>
using namespace std;

int expo(int a ,int b)
{
    int ans;
    if(b==0)
    {
        return 1;
    }
    else if(b==1)
    {
        return a;
    }
    else{
        if(b%2==0)
        {
             ans=expo(a,b/2);
             return ans*ans;
        }
        else{
            ans=expo(a,(b-1)/2);
            return a*ans*ans;
        }
    }
}

int main()
{
    int x,y;
    cin>>x>>y;
    int r=expo(x,y);
    cout<<r<<endl;
}