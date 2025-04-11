#include<iostream>
using namespace std;

int sum(int arr[],int size)
{
    int sum=0;
    for (int i = 0; i < size; i++)
    {
        sum=sum+arr[i];
    }
     return sum; 
}

int main(){
    int size;
    cout<<"enter size of array"<<endl;
    cin>>size;
    int array[1000];
    cout<<"enter elements of array"<<endl;
    for (int  i = 0; i < size; i++)
    {
        cin>>array[i];
    }
    
    cout<<"The sum of elements of array is:"<<sum(array,size);

    return 0;
}