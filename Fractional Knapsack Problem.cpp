/* C++ Program to Solve
the Knapsack Problem
using the Greedy Method
Time Complexity: O(n^2) */
#include <iostream>
using namespace std;

int getMaxIndex(double arr[], int n)
{
    double maximum = arr[0];
    int index;
    for(int i = 1; i < n; i++)
    {
        if(arr[i] > maximum)
        {
            maximum = arr[i];
            index = i;
        }
    }
    return index;
}

int main()
{
    int n;
    cout<<"Enter number of items: ";
    cin>>n;
    double profits[n], weights[n], pw[n];
    cout<<"Enter profit values of items: ";
    for(int i = 0; i < n; i++)
        cin>>profits[i];
    cout<<"Enter weight values of items: ";
    for(int i = 0; i < n; i++)
    {
        cin>>weights[i];
        pw[i] = profits[i]/weights[i];
    }
    double capacity, tot_profit = 0.0;
    cout<<"Enter capacity of Knapsack: ";
    cin>>capacity;

    while(capacity > 0)
    {
        int index = getMaxIndex(pw, n);
        if (capacity > weights[index])
        {
            capacity -= weights[index];
            tot_profit += profits[index];
            pw[index] = -1;
        }
        else
        {
            double frac = capacity / weights[index];
            tot_profit += frac * profits[index];
            break;
        }
    }
    cout<<"\nMaximum Profit = "<<tot_profit<<endl;
    return 0;
}
