#include<iostream>
#include<string>
using namespace std;

class binary
{
    private:
          string s;
       void chk_bin(void);
    public:
       void read(void);
       void ones(void);
       void display(void);
};

void binary::read()
{
    cout<<"Enter a binary number:";
    cin>>s;
}
void binary::chk_bin()
{
    for (int i = 0; i < s.length(); i++)
    {
       if(s.at(i)!='0' && s.at(i)!='1')
       {
         cout<<"Incorrect binary format!!";
         exit(0);
       }
    }
    
}
void binary :: ones()
 {
    chk_bin();
    for (int i = 0; i < s.length(); i++)
    {
       if(s.at(i)=='0'){
        s.at(i)='1';
       }
       else if(s.at(i)=='1'){
        s.at(i)='0';
       }
    }  
 }

void binary :: display(void)
{
    for (int i = 0; i < s.length(); i++)
    {
       cout<<s.at(i);
    }
}



int main(){
    binary b;
    //cin>>b.s; will give error!! as s is private member
    b.read();
    //b.chk_bin(); will give error as chk_bin is pprivate number
    b.ones();
    b.display();
    return 0;
}