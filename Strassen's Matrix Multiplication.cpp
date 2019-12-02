/* C++ Program to Implement
Strassen's Matrix Multiplication
using Divide & Conquer Method
Time Complexity: O(n^2.81)*/
#include <iostream>
using namespace std;

void inputMatrix(int mat[2][2])
{
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
            cin>>mat[i][j];
}

void displayMatrix(int mat[2][2])
{
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 2; j++)
            cout<<mat[i][j]<<" ";
        cout<<endl;
    }
}

int main()
{
    int A[2][2], B[2][2], C[2][2];
    cout<<"Enter the values of Matrix A"<<endl;
    inputMatrix(A);
    cout<<"Enter the values of Matrix B"<<endl;
    inputMatrix(B);

    int p1 = A[0][0] * (B[0][1] - B[1][1]);
    int p2 = B[1][1] * (A[0][0] + A[0][1]);
    int p3 = B[0][0] * (A[1][0] + A[1][1]);
    int p4 = A[1][1] * (B[1][0] - B[0][0]);
    int p5 = (A[0][0] + A[1][1]) * (B[0][0] + B[1][1]);
    int p6 = (A[0][1] - A[1][1]) * (B[1][0] + B[1][1]);
    int p7 = (A[0][0] - A[1][0]) * (B[0][0] + B[0][1]);

    C[0][0] = p4 + p5 + p6 - p2;
    C[0][1] = p1 + p2;
    C[1][0] = p3 + p4;
    C[1][1] = p1 - p3 + p5 - p7;

    cout<<"\nMatrix A"<<endl;
    displayMatrix(A);
    cout<<"Matrix B"<<endl;
    displayMatrix(B);
    cout<<"\nMatrix C"<<endl;
    displayMatrix(C);
    return 0;
}
