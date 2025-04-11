// #include<iostream>
// #include<bits/stdc++.h>

// using namespace std;
 
// class Stack {
//     // Two inbuilt queues
//     queue<int> q1, q2;
 
// public:
//     void push(int x)
//     {
//         // Push x first in empty q2
//         q2.push(x);
 
//         // Push all the remaining
//         // elements in q1 to q2.
//         while (!q1.empty()) {
//             q2.push(q1.front());
//             q1.pop();
//         }
 
//         // swap the names of two queues
//         queue<int> q = q1;
//         q1 = q2;
//         q2 = q;
//     }
 
//     void pop()
//     {
//         // if no elements are there in q1
//         if (q1.empty())
//             return;
//         q1.pop();
//     }
 
//     int top()
//     {
//         if (q1.empty())
//             return -1;
//         return q1.front();
//     }
 
//     int size() { return q1.size(); }
// };
 
// // Driver code
// int main()
// {
//     Stack s;
//     s.push(1);
//     s.push(2);
//     s.push(3);
 
//     cout << "current size: " << s.size() << endl;
//     cout << s.top() << endl;
//     s.pop();
//     cout << s.top() << endl;
//     s.pop();
//     cout << s.top() << endl;
 
//     cout << "current size: " << s.size() << endl;
//     return 0;
// }
#include<iostream>
using namespace std;

class queue
{
    int front=-1,rear=-1,n;
    public:
       int q[4];
       void enqueue(int x)
       {
           if(rear==4){cout<<"OVERFLOW"; return;}
           else{
             if(front==-1) //for single element
           {
              front=0;
           }
            rear++;
            q[rear]=x;
           }
       }

       int dequeue(void)
       {
        int l;
          if(front==-1)
          {
            cout<<"UNDERFLOW"; 
            return -1;
          }
          else{
            l=q[front];
            front++;
            return l;
          }
       }

       void access(void)
       {
            
       }

};

int main(){
    
    queue q1,q2;
    q1.enqueue(1);
    q1.enqueue(4);
    q1.enqueue(5);
    q1.enqueue(7);
    q2.enqueue(q1.dequeue());
    q2.enqueue(q1.dequeue());
    q2.enqueue(q1.dequeue());
    q2.enqueue(q1.dequeue());
    cout<<"The elements in reverse order is:"<<endl;
    q2.access();
    q2.access();
    q2.access();
    q2.access();
    return 0;
}