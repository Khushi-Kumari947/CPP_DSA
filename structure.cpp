#include<iostream>
using namespace std;

struct employee
{
    int eid;
    string name;
    float salary;
};

int main()
{
    struct employee E[2];
    cout<<"Enter employees details \n";
    for (int i = 0; i < 2; i++)
    {
        cout<<"Enter details of employe "<<i+1<<"\n ";
        cin>>E[i].eid;
        cout<<"\n";
        cin>>E[i].name;
        cout<<"\n";
        cin>>E[i].salary;
    }
    // E[0].eid=1;
    // E[0].name="HARRY";
    // E[0].salary=12000000;
    cout<<"The details of employees are:\n";
    for (int i = 0; i < 2; i++)
    {
        cout<<"Details of employee "<<i+1<<" is \n";
        cout<<E[i].eid<<endl;
        cout<<E[i].name<<endl;
        cout<<E[i].salary<<endl;
    }
    // cout<<E[0].name<<endl;
    // cout<<E[0].eid<<endl;
    // cout<<E[0].salary<<endl;
    return 0;
}