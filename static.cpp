#include<iostream>
using namespace std;

class employee
{
    int Id;
    static int count;
    public:
       void setData(void)
       {
          cout<<"Enter employee Id"<<endl;
          cin>>Id;
          count++;
       }

       void getData(void)
       {
           cout<<"Id of this employee is:"<<Id<<"and this is employee number"<<count<<endl;
       }

       static void getCount(void)
       {
           /*cout<<Id; throws an error as static gunctions have access to 
           static data and statis function only */
           cout<<"the Value of count is:"<<count<<endl;
       }

};

int employee:: count;//int employee:: count=1000;

int main(){
    employee rohan;
    employee harry;
    employee lovish;
    rohan.setData();
    rohan.getData();
    employee::getCount();
    harry.setData();
    harry.getData();
    employee::getCount();
    lovish.setData();
    lovish.getData();
    employee::getCount();
    return 0;
}