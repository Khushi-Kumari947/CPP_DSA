#include<iostream>
using namespace std;

class complex
{
    private:
       int a,b;
    public:
       
       complex()
       {
             a=0;
             b=0;
       }

       void setData(int x,int y)
       {
        a=x;
        b=y;
       }

       void getData()
       {
        cout<<"a = "<<a<<" b = "<<b<<endl;
       }

       complex operator -()
       {
        complex temp ;
        temp.a=-a;
        temp.b=-b;
        return temp;

       }
};

int main(){
    complex c1,c2,c3;
    c1.setData(3,5);
    // c2.setData(4,0);
    // c2=c1.operator-();
    c2=-c1;
    c2.getData();
    
     std::cout<<"Hello World";
    
    integer i1(3),i2(5),i3,i4;
    i3=++i1;
    i1.display();
    i3.display();
    i4=i2++;
    i2.display();
    i4.display();

    return 0;
}



class integer
{
    private:
    int x;
    public:
      integer()
      {
          x=0;
      }
      integer(int a)
      {
          this->x=a;
      }
      
      void display()
      {
          cout<<"x = "<<x<<endl;
      }
      
      integer operator++()
      {
          integer i;
          i.x=++x;
          return i;
      }
      
       integer operator++(int)
      {
          integer i;
          i.x=x++;
          return i;
      }
};