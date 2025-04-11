#include<iostream>
using namespace std;
int glo=9;
void print()
{
    //int glo=10;
    cout<<glo<<"\n";
}

int main()
{
    int a=4;
    int b=5;
    char c='a';
    float pi=3.14;
    int glo=9;
    glo=56;
    bool h=false;
    print();
    cout<<"the value of a is "<<a<<" the value of b is" <<b;
    cout<<"\n the value of pi is "<<pi;
    cout<<"\n the value of c is "<<c;
    cout<<"\n the value of glo is "<<glo;
    cout<<"\n the value of h is "<<h;

}