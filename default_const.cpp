#include<iostream>
using namespace std;

// class simple{
//     int data1,data2;
//     public:
//         simple(int x,int y=4)
//         {
//             data1=x;
//             data2=y;
//         }
//         void printNumber(void)
//        {
//             cout<<"The number is "<<data1<<" and "<<data2<<endl;
//        }
// };

class BankDeposit{
    int principal;
    int year;
    float interestRate;
    float ReturnValue;
    public:
        BankDeposit(){}
        BankDeposit(int p,int y,float r);        
        BankDeposit(int p,int y,int r);
        void show();        

};

BankDeposit::BankDeposit(int p,int y,float r)
{
    principal=p;
    year=y;
    interestRate=r;
    ReturnValue=principal;
    for (int i = 0; i < y; i++)
    {
        ReturnValue=ReturnValue*(1+interestRate);
        /* code */
    }   
}
BankDeposit::BankDeposit(int p,int y,int r)
{
    principal=p;
    year=y;
    interestRate=float(r)/100;
    ReturnValue=principal;
    for (int i = 0; i < y; i++)
    {
        ReturnValue=ReturnValue*(1+interestRate);
        /* code */
    }   
}

void BankDeposit::show()
{
    cout<<endl<<"principal amount was"<<principal<<"end return amount after"
    <<year<<"is"<<ReturnValue<<endl;

}

int main(){
    // simple s1(2);
    // s1.printNumber();
    BankDeposit bd1,bd2,bd3;
    int p,y;
    float r;
    int R;
    cout<<"enter the value of p,y and r"<<endl;
    cin>>p>>y>>r;
    bd1=BankDeposit(p,y,r);
    bd1.show();
    cout<<"enter the value of p,y and R"<<endl;
    cin>>p>>y>>R;
    bd2=BankDeposit(p,y,R);
    bd2.show();

    return 0;
}