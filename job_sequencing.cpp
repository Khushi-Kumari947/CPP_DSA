#include <iostream>
#include<vector>
#include<algorithm>
#include<stdlib.h>
#include <climits>

using namespace std;

class job
{
    public:
   
       int job_id;
       int job_deadline;
       int profit;

       job(int id,int dl,int pr)
       {
        job_id=id;
        job_deadline=dl;
        profit=pr;
       }

};

class Job_seq{
    public:

static bool cmp(job j1,job j2)
{
    return(j1.profit>j2.profit);
}

vector<int> MaxProfit(job arr[],int n)
{
    sort(arr,arr+n,cmp);
    
    int max_dead=INT_MIN;
    for(int i=0;i<n;i++)
    {
        max_dead=max(max_dead,arr[i].job_deadline);
    }

    vector<int> job_sequencing(max_dead+1,-1);
    
    int max_profit=0;
    int count=0;
    for(int i=0;i<n;i++)
    {
         int ID=arr[i].job_id;
         int dead=arr[i].job_deadline;
         int pro=arr[i].profit;

         for(int k=dead;k>0;k--)
         {
            if(job_sequencing[k]==-1)
            {
                job_sequencing[k]=ID;
                count++;
                max_profit+=pro;
                break;
            }
         }

    }
    vector<int> ans;
    ans.push_back(count);
    ans.push_back(max_profit);
    return ans;
}

};

int main()
{
    job j[]={job(1,4,20),job(2,1,1),job(3,1,40),job(4,1,30)};
    Job_seq ob;
    vector<int> ans=ob.MaxProfit(j,4);
    cout<<ans[0]<<" "<<ans[1]<<endl;
}
