/* C++ Program to Solve
the Knapsack Problem
using Dynamic Programming
Time Complexity: O(nm) */
#include <iostream>
using namespace std;

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int getKnapsackProfit(int m, int profits[], int weights[], int n)
{
    int K[n+1][m+1];
    for(int i = 0; i <= n; i++)
    {
        for(int w = 0; w <= m; w++)
        {
            if(i == 0 || w == 0)
                K[i][w] = 0;
            else if(weights[i-1] <= w)
                K[i][w] = max(K[i-1][w], (K[i-1][w - weights[i-1]]+profits[i-1]));

            else
                K[i][w] = K[i-1][w];
        }
    }
    return K[n][m];
}


int main()
{
    int n;
    cout<<"Enter number of items: ";
    cin>>n;
    int profits[n], weights[n];
    cout<<"Enter profit values of items: ";
    for(int i = 0; i < n; i++)
        cin>>profits[i];
    cout<<"Enter weight values of items: ";
    for(int i = 0; i < n; i++)
        cin>>weights[i];
    int m;
    cout<<"Enter capacity of the Knapsack: ";
    cin>>m;
    int profit = getKnapsackProfit(m, profits, weights, n);
    cout<<"\nMaximum Profit = "<<profit;
    return 0;
}
