/* C++ Program to Implement
Prims's Algorithm
for Minimum Spanning Trees
Time Complexity: O(n^2)*/
#include <iostream>
using namespace std;
int weights[100][100], visited[100], n;

int getCostPrim()
{
    int ne = 1, minimum, mincost = 0, a, b;
    visited[0] = 1;
    cout<<"\nEdges of Minimum Spanning Tree"<<endl;
    while (ne < n)
    {
        minimum = INT_MAX;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(weights[i][j] < minimum && visited[i])
                {
                    minimum = weights[i][j];
                    a = i;
                    b = j;
                }
            }
        }
        if(!visited[b])
        {
            cout<<"Edge ("<<a<<","<<b<<"): "<<minimum<<endl;
            ne += 1;
            mincost += minimum;
            visited[b] = 1;
        }
        weights[a][b] = weights[b][a] = INT_MAX;
    }
    return mincost;
}

int main()
{
    cout<<"Enter number of vertices: ";
    cin>>n;
    cout<<"Enter weight matrix"<<endl;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin>>weights[i][j];
            if(weights[i][j] == 0)
                weights[i][j] = INT_MAX;
        }
        visited[i] = 0;
    }
    int cost = getCostPrim();
    cout<<"\nCost of Minimum Spanning Tree = "<<cost<<endl;
    return 0;
}
