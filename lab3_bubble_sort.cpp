//include <bits/stdc++.h>
#include <iostream>
#include<vector>
#include<algorithm>
#include<stdlib.h>
#include <climits>
using namespace std;

class Sorting
{
private:
    int *arr;
    int algo;
    int n;

    void bubbleSort(int *ar, int size)
    {
        // Base case
        if (size == 1)
            return;

        for (int i = 0; i < size - 1; i++)
            if (ar[i] > ar[i + 1])
                swap(ar[i], ar[i + 1]);

        bubbleSort(ar, size - 1);
    }

public:
    Sorting(int *x, int a, int size)
    {
        arr = x;
        algo = a;
        n = size;
    }

    /* Function to print an array */
    void printArray()
    {
        for (int i = 0; i < n; i++)
            printf("%d ", arr[i]);
        printf("\n");
    }

    void sort()
    {
        if (algo == 1)
        {
            bubbleSort(arr, n);
        }
    }
};

int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    // int n = sizeof(arr) / sizeof(arr[0]);
    // cout << "Array before sorting:" << endl;
    Sorting S(arr, 1, 7);
    S.printArray();
    S.sort();
    S.printArray();
    // printArray(arr, n);
    // bubbleSort(arr, n);
    // printf("Sorted array : \n");
    // printArray(arr, n);
    return 0;
}
