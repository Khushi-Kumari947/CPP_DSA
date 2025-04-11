#include <iostream>
#include <queue>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

node *BuildTree(node *root)
{
    int data;
    cout << "enter the data " << endl;
    cin >> data;
    root = new node(data);
    if (data == -1)
    {
        return NULL;
    }
    cout << "enter the data for inserting in left " << data << endl;
    root->left = BuildTree(root->left);
    cout << "enter the data for inserting in right " << data << endl;
    root->right = BuildTree(root->right);
    return root;
}

void levelOrderTraversal(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }

        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

void Inordertrav(node * root)
{
      if(root==NULL)
      {
        return;
      }
      
      Inordertrav(root->left);
      cout<<root->data<<" ";
      Inordertrav(root->right);
}
void Preordertrav(node * root)
{
      if(root==NULL)
      {
        return;
      }
      
      cout<<root->data<<" ";
      Preordertrav(root->left);
      Preordertrav(root->right);
}
void Postordertrav(node * root)
{
      if(root==NULL)
      {
        return;
      }
      
      Postordertrav(root->left);
      Postordertrav(root->right);
      cout<<root->data<<" ";
}

void BuildeTreeFromBFS(node * &root)
{
    int data;
    queue<node *> q;
    cout<<"enter data for root"<<endl;
    cin>> data;
    root=new node(data);
    q.push(root);
    while(!q.empty())
    {
        node * temp= q.front();
        q.pop();
        cout<<"enter left node for"<<temp->data<<endl;
        int ld;
        cin>>ld;
        if(ld!=-1)
        {
            temp->left=new node(ld);
            q.push(temp->left);
            
        }
        cout<<"enter right node for"<<temp->data<<endl;
        int rd;
        cin>>rd;
        if(rd!=-1)
        {
            temp->right=new node(rd);
            q.push(temp->right);

        }
    }
}

int main()
{

    node *root = NULL;
    // // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    // root = BuildTree(root);
    // levelOrderTraversal(root);
    // cout<<endl;
    // Inordertrav(root);
    // cout<<endl;
    // Preordertrav(root);
    // cout<<endl;
    // Postordertrav(root);
    // return 0;
    BuildeTreeFromBFS(root);
    levelOrderTraversal(root);
}