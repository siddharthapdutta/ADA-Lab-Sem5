/* C++ Program to Implement
Quick Sort
using Divide & Conquer
Worst Case Time Complexity: O(n^2)
Best Case Time Complexity: O(nlogn)*/
#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int first, int last)
{
    int i = first;
    int j = last;
    int pivot = arr[first];
    while (i < j)
    {
        while(pivot >= arr[i] && i <= last)
            i += 1;
        while(pivot < arr[j] && j >= first)
            j -= 1;
        if (i < j)
            swap(&arr[i], &arr[j]);
    }
    swap(&arr[j], &arr[first]);
    return j;

}

void quickSort(int arr[], int first, int last)
{
    if (first < last)
    {
        int index = partition(arr, first, last);
        quickSort(arr, first, index-1);
        quickSort(arr, index+1, last);
    }
}

int main()
{
    int n;
    cout<<"Enter number of elements: ";
    cin>>n;
    int arr[n];
    cout<<"Enter elements of the array: ";
    for(int i = 0; i < n; i++)
        cin>>arr[i];
    quickSort(arr, 0, n-1);
    cout<<"\nSorted Array: ";
    for(int i = 0; i < n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}
