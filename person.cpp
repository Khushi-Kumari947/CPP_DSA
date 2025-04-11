#include <iostream>
using namespace std;
class person
{
    string name;
    int roll;
    string branch;

public:
    // person()
    // {
    //     name= "khushi";
    //     roll=22;
    //     branch="ppt";
    //     cout << "constructor called";
    // } // default constructor of class
    person (string name, int rol, string br)//parameterised constructor
    {
        this->name= name;
        roll=rol;
        branch=br;
    }
    void display(){
        cout<<"name is "<<name<<" roll no is "<<roll<<" branch is "<<branch<<endl;
    }
};
int main()
{
    person f1("nothing",111,"random");
    f1.display();
    return 0;
}