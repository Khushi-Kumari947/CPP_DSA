#include<iostream>
using namespace std;

class employee
{
    int Id;
    int salary;
    public:
       void setData(void)
       {
          salary=122;
          cout<<"Enter employee Id"<<endl;
          cin>>Id;
       }

       void getData(void)
       {
           cout<<"Id of this employee is:"<<Id<<endl;
       }
};


int main(){
    employee RK[5];
    for (int i = 0; i < 5; i++)
    {
        RK[i].setData();
        RK[i].getData();
    }
    
  
  
  
  
  
  
  
    return 0;
}