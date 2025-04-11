#include<iostream>
#include<iomanip>
using namespace std;
 
int main()
{
    for (int i = 0; i < 10; i++)
    {
        cout<<setw(2)<<i<<endl;
        /* code */
    }
    int i=0;
    while(i<40)
    {
        cout<<setw(2)<<i<<endl;
        i++;
    }
    i=0;
    do
    {
        cout<<setw(2)<<i<<endl;
        i++;
    }
    while(false);


    
}