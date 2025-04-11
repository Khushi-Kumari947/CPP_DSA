#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    int i=1,n;
    cout<<"Enter the number:";
    cin>>n;
    do
    {
        cout<<n<<" x "<<setw(2)<<i<<" = "<<setw(2)<<n*i<<endl;
        i++;
    } while (i<=10);
    
}