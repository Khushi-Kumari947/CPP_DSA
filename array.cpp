#include<iostream>
using namespace std;



int main(){
    int marks[4]={23,56,78,90};
    for(int i=0;i<4;i++)
    cout<<marks[i]<<endl;
    
    int * p=marks;
    for(int i=0;i<4;i++)
    {
        cout<<"The marks of student "<<i<<" is "<<*(p+i)<<endl;
    }
    return 0;
}