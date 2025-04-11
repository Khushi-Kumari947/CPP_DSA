#include<iostream>
using namespace std;

int main(){
    for (int i = 0; i < 10; i++)
    {
        if(i==5) continue;
        cout<<"THIS IS:"<<i<<endl;
        /* code */
    }
    cout<<"THIS IS ANOTHER FOR LOOP!!"<<endl;
    for (int i = 0; i < 10; i++)
    {
        if(i==5) break;
        cout<<"THIS IS:"<<i<<endl;
        /* code */
    }
    
    return 0;
}