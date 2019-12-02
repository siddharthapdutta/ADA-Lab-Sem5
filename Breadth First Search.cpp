/* C++ Program to Implement
Graph Traversal Method
using Breadth-First-Search
Time Complexity: O(n^2) */
#include <iostream>
using namespace std;
int adjMatrix[100][100], n, visited[100];
int queue[100], rear = -1, front;

int bfs(int node)
{
    visited[node] = 1;
    for(int i = 0; i < n; i++)
    {
        if(adjMatrix[node][i] && !visited[i])
        {
            cout<<"Node "<<node<<" -> Node "<<i<<endl;
            queue[++rear] = i;
            visited[i] = 1;
        }
    }
    if (front <= rear)
        bfs(queue[front++]);
}

int main()
{
    cout<<"Enter number of vertices: ";
    cin>>n;
    cout<<"Enter adjacency matrix"<<endl;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin>>adjMatrix[i][j];
    cout<<"\nGraph Traversal using Breadth-First-Search"<<endl;
    bfs(0);
    return 0;
}
