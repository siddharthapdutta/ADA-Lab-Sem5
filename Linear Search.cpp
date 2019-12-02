// C++ Program to Implement Linear Search
// Time Complexity: O(n)
#include <iostream>
using namespace std;

int main()
{
    int n, i;
    cout<<"Enter number of elements in the array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter elements of the array: ";
    for(int i = 0; i < n; i++)
        cin>>arr[i];
    int target;
    cout<<"Enter target element: ";
    cin>>target;
    for(i = 0; i < n; i++)
    {
        if (arr[i] == target)
            break;
    }
    if (i == n)
        cout<<"\nElement not found!"<<endl;
    else
        cout<<"\nElement found at index: "<<i<<endl;
    return 0;
}
