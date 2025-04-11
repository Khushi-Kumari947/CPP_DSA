#include<iostream>
using namespace std;

class integer
{
    private:
       int x;
    public:
        void setData(int a)
        {
            x=a;
        }

        void showData()
        {
            cout<<"x = "<<x<<endl;
        }

        integer operator++()//pre increment
        {
            integer i;
            i.x=++x;
            return i;
        }

        integer operator++(int)//post increment
        {
            integer i;
            i.x=x++;
            return i;
        }
};

int main(){
    
   integer i1,i2,i3;
    i1.setData(3);
    i1.showData();
    i2=++i1;
    i1.showData();
    i2.showData();
    i3=i1++;
    i3.showData();
    i1.showData();
    return 0;
}