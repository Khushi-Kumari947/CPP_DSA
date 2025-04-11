#include<iostream>
using namespace std;
int count=0;
class num
{
    public:
       num()
       {
        count++;
        cout<<"this is the time when constructor is called for object number"<<count<<endl;
       }
       ~num()
       {
        cout<<"this is the time when destructor is called for object number"<<count<<endl;
        count--;
       }
};

int main(){
    cout<<"Inside main function"<<endl;
    cout<<"creating first object"<<endl;
    num n1;
    {
        cout<<"entering into block"<<endl;
        cout<<"creating two more objects"<<endl;
        num n2,n3;
        cout<<"exiting into block"<<endl;
    }
    cout<<"back to main function";
    return 0;
}