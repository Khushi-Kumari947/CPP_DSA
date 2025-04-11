// // CPP program to implement Queue using
// // two stacks with costly enQueue()
// #include <bits/stdc++.h>
// using namespace std;
 
// struct Queue {
//     stack<int> s1, s2;
 
//     void enQueue(int x)
//     {
//         // Move all elements from s1 to s2
//         while (!s1.empty()) {
//             s2.push(s1.top());
//             s1.pop();
//         }
 
//         // Push item into s1
//         s1.push(x);
 
//         // Push everything back to s1
//         while (!s2.empty()) {
//             s1.push(s2.top());
//             s2.pop();
//         }
//     }
 
//     // Dequeue an item from the queue
//     int deQueue()
//     {
//         // if first stack is empty
//         if (s1.empty()) {
//             return -1;
//         }
 
//         // Return top of s1
//         int x = s1.top();
//         s1.pop();
//         return x;
//     }
// };
 
// // Driver code
// int main()
// {
//     Queue q;
//     q.enQueue(1);
//     q.enQueue(2);
//     q.enQueue(3);
 
//     cout << q.deQueue() << '\n';
//     cout << q.deQueue() << '\n';
//     cout << q.deQueue() << '\n';
 
//     return 0;
// }

#include<iostream>
using namespace std;

class stack
{
    int top=0;
    public:
       int s[4];
       void push(int x)
       {
          if(top==4){cout<<"overflow";}
          else{
            s[top]=x;
            top++;
          }
       }
    
    int pop(void)
    {
        int l;
        if(top<0){cout<<"underflow";
            return -1;
        }
        else{
            l=s[top-1];
            top--;
            return l;
        }
    }

    void access(void)
    {
            cout<<s[top-1]<<endl;
            top--;
    }
};

int main(){
    stack s1,s2;
    s1.push(11);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    //s1.top();
    s2.push(s1.pop());
    s2.push(s1.pop());
    s2.push(s1.pop());
    s2.push(s1.pop());
    // cout<<"dikhi?:";
    cout<<"The element in the same order:"<<endl;
    s2.access();
    s2.access();
    s2.access();
    s2.access();
    // // return 0;
}