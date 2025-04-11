#include <iostream>
#include<vector>
#include<algorithm>
#include<stdlib.h>
#include <climits>

//include <bits/stdc++.h>
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

class job_seq
{
    public:
        int size_array;
        vector<int> ans;
        vector<bool> slot;

        int max_profit(job arr[],)
}