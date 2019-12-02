/* C++ Program to Implement
Kruskal's Algorithm
for Minimum Spanning Trees
Time Complexity: O(n^2) */
#include <iostream>
using namespace std;
int weights[100][100], parent[100], n;

int find(int i)
{
    while(parent[i])
        i = parent[i];
    return i;
}

int uni(int i, int j)
{
    if (i != j)
    {
        parent[j] = i;
        return 1;
    }
    return 0;
}

int getCostKruskal()
{
    int ne = 1, minimum, mincost = 0, a, b, u, v;
    cout<<"\nEdges of Minimum Spanning Tree"<<endl;
    while(ne < n)
    {
        minimum = INT_MAX;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(weights[i][j] < minimum)
                {
                    minimum = weights[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }
        u = find(u);
        v = find(v);
        if (uni(u,v))
        {
            cout<<"Edge ("<<a<<","<<b<<"): "<<minimum<<endl;
            mincost += minimum;
            ne +=1;
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
    }
    int cost = getCostKruskal();
    cout<<"\nCost of Minimum Spanning Tree = "<<cost<<endl;
    return 0;
}
