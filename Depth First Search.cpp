/* C++ Program to Implement
Graph Traversal Method
using Depth-First-Search
Time Complexity: O(n^2)*/
#include <iostream>
using namespace std;
int adjMatrix[100][100], n, visited[100];

int dfs(int node)
{
    visited[node] = 1;
    for(int i = 0; i < n; i++)
    {
        if(adjMatrix[node][i] && !visited[i])
        {
            cout<<"Node "<<node<<" -> Node "<<i<<endl;
            dfs(i);
        }
    }
}

int main()
{
    cout<<"Enter number of vertices: ";
    cin>>n;
    cout<<"Enter adjacency matrix"<<endl;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin>>adjMatrix[i][j];
    cout<<"\nGraph Traversal using Depth-First-Search"<<endl;
    dfs(0);
    return 0;
}
