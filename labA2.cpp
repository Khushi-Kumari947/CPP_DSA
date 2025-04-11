#include<iostream>
using namespace std;

float expo(float a ,float b)
{
    float ans;
    if(b==0)
    {
        return 1;
    }
    else if(b==1)
    {
        return a;
    }
    else{
        if(int(b)%2==0)
        {
             ans=expo(a,b/2);
             return ans*ans;
        }
        else{
            ans=expo(a,(b-1)/2);
            return a*ans*ans;
        }
    }
}

class inflation
{
    private:
        float current_val;
        float inflation_rate;
        float num_period;
    public:
        inflation(float cr,float ifr,float time )
        {
            current_val=cr;
            inflation_rate=ifr;
            num_period=time;
        }

        int calci_inflation()
        {
             float future_val;
             float y=expo(inflation_rate+1,num_period);
             future_val=current_val*y;
             return future_val;

        }
        
};

int main()
{
    inflation iff(1500,0.064,5);
    cout<<"Future cost of 1500 rupees will be"<<endl;
    float f=iff.calci_inflation();
    cout<<f<<endl;

}