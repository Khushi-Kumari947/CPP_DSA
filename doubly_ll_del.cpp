#include<iostream>
using namespace std;

class node
{
       public:
          int data ;
          node * prev;
          node * next;
        
        node(int data)
        {
            this->data=data;
            this->prev=NULL;
            this->next=NULL;
        }

        ~node()
        {
            int val=this->data;
            if(this->next != NULL)
            {
                delete next;
                this->next=NULL;
            }
            cout<<"memory freed for node with data "<<val<<endl;
        }
        
};


void print(node * head){
    node * temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void InsertAtBeg(node * &head,int d)
{
    if(head==NULL)
    {
        node * temp=new node(d);
        head=temp;
    }
    else
    {
        node * temp=new node(d);
        temp->next=head;
        head->prev=temp;
        head=temp;
    }
}

void InsertAtEnd(node * &head,int d)
{
    if(head==NULL)
    {
        node * temp=new node(d);
        head=temp;
    }
    else{
        node * temp=head;
        node * n=new node(d);
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=n;
        n->prev=temp;
    }
}

void InsertAtPos(node * &head,int d,int pos)
{
    if(pos==1)
    {
       InsertAtBeg(head,d);
       return;
    }
    else{
        node * NodeToINSRT=new node(d);
        node * temp=head;
        int cnt=1;
        while(cnt<pos-1)
        {
            temp=temp->next;
            cnt++;
        }
        if(temp->next==NULL)
        {
            InsertAtEnd(head,d);
            return;
        }
        NodeToINSRT->next=temp->next;
        temp->next->prev=NodeToINSRT;
        temp->next=NodeToINSRT;
        NodeToINSRT->prev=temp;
    }
}

void Delete(node * &head,int pos)
{
    if(pos==1)
    {
        node * temp=head;
        temp->next->prev=NULL;
        head=temp->next;
        temp->next=NULL;
        delete temp;
    } 
    else{
        node * curr=head;
        node * prev=NULL;
        int cnt=1;
        while(cnt<pos)
        {
            prev=curr;
            curr=curr->next;
            cnt++;
        }
        curr->prev=NULL;
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
    }
}


int main(){
    node * head=NULL;
    InsertAtBeg(head,20);
    print(head);
    InsertAtBeg(head,30);
    print(head);
    InsertAtBeg(head,40);
    print(head);
    InsertAtEnd(head,50);
    print(head);
    InsertAtEnd(head,60);
    print(head);
    InsertAtPos(head,80,3);
    print(head);
    InsertAtPos(head,90,1);
    print(head);
    InsertAtPos(head,100,8);
    print(head);
    Delete(head,1);
    print(head);
    Delete(head,4);
    print(head);
    return 0;
}