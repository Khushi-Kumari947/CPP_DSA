#include<iostream>
#include<stdlib.h>
#include<vector>
#include<string>
using namespace std;

int partition(vector<int>& nums,int low,int high){
    
    int pivot=nums[high];
    int i=low-1;

    for(int j=low;j<high;j++){
        if(nums[j]<pivot){
            i++;
            swap(nums[j],nums[i]);
        }
    }
    swap(nums[i+1],nums[high]);
    return i+1;
}

void quickSort(vector<int> &nums,int low,int high){
    if(low<high){
        int p=partition(nums,low,high);

        quickSort(nums,low,p-1);
        quickSort(nums,p+1,high);
    }
}

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        quickSort(nums,0,n-1);
        return nums;
    }
};