#include <iostream>
#include<iomanip>
using namespace std;

int main()
{
     int i=1;
    int n;
    cin>>n;
    while(i<=n)
    {
        int j=1;
        while(j<=n)
        {
            char ch='A'+i+j-2;
            cout<<ch;
            j++;
        }
        cout<<endl;
        i++;
    }


// NEW PATTERN 


    i=1;
    // int n;
    // cin>>n;
    while(i<=n)
    {
        int j=1;
        while(j<=n-i+1)
        {
            cout<<setw(2)<<j ;
            j++;
        }
        int star=1;
        while(star<=i*2-2)
        {
            cout<<" *";
            star++;
        }
        int start=n-i+1;
        while(start)
        {
            cout<<setw(2)<<start ;
            start--;
        }
        cout<<endl;
        i++;
    }
}