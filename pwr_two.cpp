#include<iostream>
using namespace std;
bool power_of_two(int n)
{
    if((n&n-1)==0)
    {
        return true;
    }
    return false;
}

int main(){
    
    int num;
    cin>>num;
    bool f=power_of_two(num);
    if(f)
    {
        cout<<"yes";
    }
    else
    cout<<"no";
    return 0;
}