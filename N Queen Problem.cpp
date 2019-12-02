/* C++ Program to solve
the N-Queen Problem
using Backtracking
Time Complexity: O(n^n) */
#include <iostream>
using namespace std;
int board[100][100];

void printBoard(int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            cout<<board[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
}

bool isSafe(int row, int col, int n)
{
    // Check if the column is safe
    for(int i = 0; i < row; i++)
        if(board[i][col])
            return false;
    // Check if upper left diagonal is safe
    for(int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if(board[i][j])
            return false;
    // Check if upper right diagonal is safe
    for(int i = row, j = col; i >= 0 && j < n; i--, j++)
        if(board[i][j])
            return false;
    return true;
}

bool solveBoard(int row, int n)
{
    // Recursive Base Condition: Last Row Completed
    if (row == n)
    {
        printBoard(n);
        return true;
    }
    bool result = false;
    for(int col = 0; col < n; col++)
    {
        if(isSafe(row, col, n))
        {
            board[row][col] = 1;
            result = solveBoard(row+1, n) || result; // Recursive into next rows
            board[row][col] = 0; // In case backtracking is required on failure
        }
    }
    return result;
}

int main()
{
    int n;
    cout<<"Enter the number of Queen's: ";
    cin>>n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
        board[i][j] = 0;
    bool result = solveBoard(0, n); // Start from Row 0
    if (result)
        cout<<"\nSolved!"<<endl;
    else
        cout<<"\nNo Possible Solutions!"<<endl;
    return 0;
}
