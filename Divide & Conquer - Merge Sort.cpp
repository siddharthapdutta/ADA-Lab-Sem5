/* C++ Program to Implement
Merge Sort
using Divide & Conquer
Complexity: O(nlogn) */
#include <iostream>
using namespace std;

void merge(int arr[], int first, int mid, int last)
{
    int i = first;
    int j = mid + 1;
    int k = 0;
    int temp[last-first+1];
    while (i <= mid && j <= last)
    {
        if (arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
    while (i <= mid)
        temp[k++] = arr[i++];
    while (j <= last)
        temp[k++] = arr[j++];

    for(int i = first; i <= last; i++)
        arr[i] = temp[i - first];
}

void mergeSort(int arr[], int first, int last)
{
    if (first < last) // Base Condition for Recursion
    {
        int mid = (first + last) / 2;
        mergeSort(arr, first, mid);
        mergeSort(arr, mid+1, last);
        merge(arr, first, mid, last);
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
    mergeSort(arr, 0, n-1);
    cout<<"\nSorted Array: ";
    for(int i = 0; i < n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}
