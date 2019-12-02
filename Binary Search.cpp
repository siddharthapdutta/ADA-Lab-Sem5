/* C++ Program to Implement
Recursive Binary Search
using Divide & Conquer
Time Complexity: O(log n) */
#include <iostream>
using namespace std;

int binarySearch(int arr[], int first, int last, int target)
{
    // Base Condition
    if (first >= last)
    {
        if (arr[first] == target)
            return first;
        else
            return -1;
    }
    else
    {
        int mid = (first + last)/2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            return binarySearch(arr, mid + 1, last, target);
        else
            return binarySearch(arr, first, mid - 1, target);
    }
}

int main()
{
    int n;
    cout<<"Enter number of elements: ";
    cin>>n;
    int arr[n];
    cout<<"Enter elements of the array: "; // Array Elements Must be Sorted
    for(int i = 0; i < n; i++)
        cin>>arr[i];
    int target = 0;
    cout<<"Enter target element: ";
    cin>>target;
    int result = binarySearch(arr, 0, n-1, target);
    if (result == -1)
        cout<<"\nElement not found!"<<endl;
    else
        cout<<"\nElement found at index: "<<result<<endl;
    return 0;
}
