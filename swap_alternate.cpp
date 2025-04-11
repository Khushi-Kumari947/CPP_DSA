#include<iostream>
using namespace std;

void PrintArray(int arr[],int n)
{
    for (int i = 0; i <n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;   
}
void swap(int arr[],int n)
{
    for (int i = 0; i < n; i+=2)
    {
        if(i+1<n)
        {
            swap(arr[i],arr[i+1]);
        }
    }   
}

int main(){
    
    int even[]={1,2,3,4,5,6};
    int odd[]={7,8,9,0,1};
    swap(even,6);
    PrintArray(even,6);    
    swap(odd,5);    
    PrintArray(odd,5);  
    return 0;
}