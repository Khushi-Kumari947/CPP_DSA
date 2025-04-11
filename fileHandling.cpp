#include<iostream>
#include<fstream>
using namespace std;

int main(){

     int rno,fee;
    char name[50];
    ofstream file_out;
    file_out.open("sample.txt");
    while(file_out)
    {
        cout<<"enter your roll number:"<<endl;
        cin>>rno;
        if(rno==-1)
        {
            break;
        }
        cout<<"enter your name:"<<endl;
        cin>>name;
        cout<<"enter your fee:"<<endl;
        cin>>fee;

        file_out<<rno<<"\t"<<name<<"\t"<<fee<<endl;
    }

    file_out.close();

    ifstream file_in;
    file_in.open("sample.txt");
    cout<<"ROLL NO."<<" "<<"Name"<<" "<<"FEE"<<endl;
    while(file_in)
    {
        file_in>>rno>>name>>fee;
        cout<<endl<<rno<<"\t"<<name<<"\t"<<fee;
    }
    file_in.close();
    return 0;
}