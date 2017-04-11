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

void transpose(int arr[3][3], float arr2[3][3])
{
    int i, j;
    for(i=0; i<3; ++i)
        for(j=0; j<3; ++j)
            arr2[j][i] = arr[i][j];
            
}
void invert(int arr[3][3], float arr2[3][3])
{
    int cof[3][3] = {0};
    int i, j;
    int determ = determinant(arr);
    minor(arr, cof);

    //cofactor
    cof[1][0] *= -1;
    cof[0][1] *= -1;
    cof[2][1] *= -1;
    cof[1][2] *= -1;

    transpose(cof, arr2);
}

void lettertonum(string x, int arr[], int length)
{
    int b;
    for (b = 0; b < length; ++b) {  //convert letter to number
        if (x[b] == ' ')
            arr[b] = 1;
        else
            arr[b] = pow((int(x[b]) + 16), 2) - 10000;
    }
}

void numtoletter(int arr[], char ans[], int length)
{
    for (int d = 0; d < length; ++d) {
            if (arr[d] == 1)
                ans[d] = ' ';
            else
                ans[d] = sqrt(arr[d] + 10000) - 16;

        }
}
void addFiller(int arr[], int &length)
{
    if (length % 3 == 2) //add 1 0 to the end of the string to make it divisible by 3
    {
        arr[length] = 1;
        ++length; //increase length by 1
    } else if (length % 3 == 1) //add 2 zeroes to the end of the string to make it divisible by 3;
    {
        arr[length] = 1;
        arr[length + 1] = 1;
        length = length + 2; //increase the length by 2
    }
}

void askAgain(bool tryAgain, bool &again, string againResp)
{
    tryAgain = true;
    while(tryAgain){
        cout << "\nDo you wish to continue (Y/N)? ";
        cin >> againResp;

        if(againResp == "y" || againResp == "Y")
        {
            again = true;
            tryAgain = false;
        }
        else if (againResp == "N" || againResp == "n")
        {
            again = false;
            tryAgain = false;
        }
        else
            tryAgain = true;
    }
}




