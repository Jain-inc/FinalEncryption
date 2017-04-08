#include <iostream>
#include <cmath>
using namespace std;

void matrixmult(int arr[3][3], int f, int arr2[], int ans[])
{
    int r, c, counter = 0, checker = 0;
    int num = f / 3; //determines how many 3x1 matrices need to be made
    while(num>0) {
        for (r = 0; r < 3; ++r) {
            for (c = 0; c < 3; ++c) {
                ans[counter] += arr[r][c] * arr2[checker];
                ++checker;
            }
            ++counter;
            checker = checker-3;
        }
        checker+=3;
        --num;
    }
}

int determinant(int arr[3][3])
{
    int r, deter = 0;
    deter = (arr[0][0]*(arr[1][1]*arr[2][2]-arr[2][1]*arr[1][2])) - (arr[0][1] * (arr[1][0]*arr[2][2]-arr[2][0]*arr[1][2])) + (arr[0][2] * (arr[1][0]*arr[2][1]-arr[2][0]*arr[1][1]));
    return deter;
}

void minor(int arr[3][3], int arr2[3][3])
{
    int i, j;
    arr2[0][0] = arr[1][1]*arr[2][2]-arr[2][1]*arr[1][2];
    arr2[0][1] = arr[1][0]*arr[2][2]-arr[2][0]*arr[1][2];
    arr2[0][2] = arr[1][0]*arr[2][1]-arr[2][0]*arr[1][1];
    arr2[1][0] = arr[0][1]*arr[2][2]-arr[2][1]*arr[0][2];
    arr2[1][1] = arr[0][0]*arr[2][2]-arr[2][0]*arr[0][2];
    arr2[1][2] = arr[0][0]*arr[2][1]-arr[2][0]*arr[0][1];
    arr2[2][0] = arr[0][1]*arr[1][2]-arr[1][1]*arr[0][2];
    arr2[2][1] = arr[0][0]*arr[1][2]-arr[1][0]*arr[0][2];
    arr2[2][2] = arr[0][0]*arr[1][1]-arr[1][0]*arr[0][1];
}

void transpose(int arr[3][3], int arr2[3][3])
{
    int i, j;
    for(i=0; i<3; ++i)
        for(j=0; j<3; ++j)
            arr2[j][i] = arr[i][j];
            
}

void DivideByDeterminant(int arr[3][3], float arr2[3][3], float d)
{
    int i, j;
    for(i=0; i<3; ++i)
        for(j=0; j<3; ++j)
            arr2[i][j] = arr[i][j]/d;

}
void whole(int arr[3][3], float arr2[3][3])
{
    int cof[3][3] = {0};
    int adj[3][3] = {0};
    int i, j;
    float determ = determinant(arr);
    minor(arr, cof);

    //cofactor
    cof[1][0] *= -1;
    cof[0][1] *= -1;
    cof[2][1] *= -1;
    cof[1][2] *= -1;

    transpose(cof, adj);

    DivideByDeterminant(adj, arr2, determ);
}

void lettertonum(string x, int arr[], int length)
{
    int b;
    for (b = 0; b < length; ++b) {  //convert letter to number
        if (x[b] == ' ')
            arr[b] = 1;
        else
            arr[b] = pow((toascii(x[b]) + 16), 2) - 10000;
    }
}

void numtoletter(int arr[], char ans[], int length)
{
    int d;
    for (int d = 0; d < length; ++d) {
            if (arr[d] == 1)
                ans[d] = ' ';
            else
                ans[d] = sqrt(arr[d] + 10000) - 16;

        }

}