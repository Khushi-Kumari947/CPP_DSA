#include<iostream>
using namespace std;

class node
{
       public:
          int data ;
          node * next;
        
        node(int data)
        {
            this->data=data;
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

void InsertAtBeg(node * &head,int d)
{
    if(head==NULL)
    {
        node * n1=new node(d);
        head=n1;
    }
    else{
        node * NodeToInsert=new node(d);
        NodeToInsert->next=head;
        head=NodeToInsert;
    }
}

void InsertAtEnd(node * &head,int d)
{
    if(head==NULL)
    {
        node * n1=new node(d);
        head=n1;
    }
    else{
        node * temp=head;
        node * n1=new node(d);
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=n1;
    }
}

void InsertAtPos(node * &head,int d,int pos)
{
    if(pos==1)
    {
        InsertAtBeg(head,d);
    }
    else{
        int cnt=1;
        node * temp=head;
        while(cnt<pos-1)
        {
            temp=temp->next;
            cnt++;
        }
        node * n3=new node(d);
        n3->next=temp->next;
        temp->next=n3;
    }
}

void print(node * head){
    node * temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void Delete(node * &head,int pos)
{
     if(pos==1)
     {
         node*temp=head;
         head=temp->next;
         temp->next=NULL;
         delete temp;
     }

     else{
        node * temp=head;
        node * prev=NULL;
        node * curr=head;
        int cnt=1;
        while(cnt<pos)
        {
            prev=curr;
            curr=curr->next;
            cnt++;
        }
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
     }
}

int main(){
    
    // node n1(10);
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
    //Delete(head,1);
    // Delete(head,1);
    return 0;
}