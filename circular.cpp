#include<iostream>
using namespace std;

class node
{
    public:
         int data;
         node * next;

    node(int data)
    {
        this->data=data;
        this->next=NULL;
    }

    ~node()
    {
        int value=this->data;
        if(this->next!=NULL)
        {
            delete next;
            next=NULL;
        }
        cout<<"Memory freed for node with data "<<value<<endl;
    }
};


void InsertAtBeg(node * &tail,int ele,int d)
{
    if(tail==NULL)
    {
        node * nn=new node(d);
        tail=nn;
        nn->next=nn;
    }
    else{
        node * curr=tail;
        while(curr->data!=ele)
        {
            curr=curr->next;
        }
        node * temp=new node(d);
        temp->next=curr->next;
        curr->next=temp;
    }
}

void Delete(node * tail,int val)
{
    if(tail==NULL)
    {
        cout<<"underflow";
    }

    else{
          node * prev=tail;
        node * curr=tail->next;
        while(curr->data!=val)
        {
            prev=curr;
            curr=curr->next;
        }
        prev->next=curr->next;
        if(curr==prev)
        {
           tail=NULL;
        }
        else if(tail==curr)
        {
             tail=prev;
        }
        curr->next=NULL;
        delete curr;
    }
}
void print(node * tail){
    node * temp=tail;
    do
    {
        cout<<tail->data<<" ";
        tail=tail->next;
    }while(tail!=temp);
    cout<<endl;
}


int main(){
    
    node * tail=NULL;
    InsertAtBeg(tail,5,20);
    print(tail);
    InsertAtBeg(tail,20,30);
    print(tail);
    InsertAtBeg(tail,30,40);
    print(tail);
    InsertAtBeg(tail,20,50);
    print(tail);
    Delete(tail,30);
    print(tail);
    Delete(tail,50);
    print(tail);
    return 0;
}