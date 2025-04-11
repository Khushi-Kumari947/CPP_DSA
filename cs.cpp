#include<iostream>
using namespace std;

int main()
{
    int age;
    cout<<"tell me your age:";
    cin>>age;
//     if(age<18 && age>0)
//     {
//         cout<<"you cannot come to my party!!";
//     }
//     else if(age<1)
//     {
//         cout<<"you are not yet born";
//     }
//     else 
//     cout<<"welcome to my part!!";
switch (age)
{
case 18:
    cout<<"you are 18!!"<<endl;
    break;
case 22:
    cout<<"you  are 22"<<endl;
    break;
case 2:
    cout<<"you are 2"<<endl;
     break;
default:
    cout<<"no special cases!!"<<endl;
    break;
}
cout<<"done with switch case!!";
}