#include<iostream>
using namespace std;

class stack
{
    private:
     int top;
     int arr[1000];
    public:
         stack()
         {
            top=-1;
         }

         void push(int x)
         {
            top++;
            arr[top]=x;
         }

         int pop()
         {
            if(top==-1)
            {
                cout<<"Underflow"<<endl;
            }
            else
            {
                int a=arr[top];
                top--;
                return a;
            }
         }

         int peek()
         {
            return arr[top];
         }
};

int main()
{
    stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout<<"Popped element is "<<s.pop()<<endl;
    cout<<"Element at the top is "<<s.peek()<<endl;
}