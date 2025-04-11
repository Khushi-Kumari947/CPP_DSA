#include<iostream>
using namespace std;

class number
{
    int n;
    public:
       number(){
        n=0;
       }
       number(int a)
       {
        n=a;
       }
       number(number &obj)
       {
        cout<<"copy constructor called"<<endl;
        n=obj.n;
       }
       void display()
       {
         cout<<"the number is"<<n<<endl;
       }
};

int main(){
    number n1,n2,n3(34),z2; 
    n3.display();
    n1.display();
    n2.display();
    number z(n3);
    z.display();
    z2=z;//copy constructor not called
    z2.display();
    number z3=z;//copy constructor  called
    z3.display();
    return 0;
}