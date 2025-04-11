#include<iostream>
using namespace std;

int main(){
    int a=34;
    int* c=&a; 
    cout<<"Address of a is:"<<c<<"\n";   
    cout<<"value of a is:"<<*c<<"\n";  
    int** d=&c; 
    cout<<"Address of c is:"<<d<<"\n";   
    // cout<<"value at d is:"<<*d<<"\n";   
    cout<<"value at address hold by d is:"<<**d<<"\n";   
    return 0;
}