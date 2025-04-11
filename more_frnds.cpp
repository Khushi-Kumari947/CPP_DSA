#include<iostream>
using namespace std;
class c2;
class c1
{
    int val;
    friend void exchange(c1 &, c2 &);
    public:
       void  intData(int a)
       {
        val=a;
       }

       void display()
        {
            cout<<val<<endl;
        }
       
};
class c2
{
    int val2;
    friend void exchange(c1 & , c2 &);  
    public:
       void  intData(int a)
       {
        val2=a;
       }

       void display()
        {
            cout<<val2<<endl;
        }
       
};

void exchange(c1 &x , c2 & y)
{
    int tmp=x.val;
    x.val=y.val2;
    y.val2=tmp;
}

int main(){
    c1 oc1;
    c2 oc2;
    oc1.intData(90);
    oc2.intData(100);
    exchange(oc1,oc2);
    cout<<"the value of c1 after exchange becomes";
    oc1.display();
    cout<<"the value of c2 after exchange becomes";
    oc2.display();
    return 0;
}