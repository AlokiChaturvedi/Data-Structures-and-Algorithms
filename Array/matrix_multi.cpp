#include <iostream>
using namespace std;

int main()
{
    int r1, c1;
    cout << "Enter the rows and columns of your array1: ";
    cin >> r1;
    cin >> c1;

    int arr1[r1][c1];
    cout << "Enter the elements of your array1: ";
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
        {
            cin >> arr1[i][j];
        }
    }
    cout << "Your first array is: " << endl;
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
        {
            cout << arr1[i][j] << " ";
        }
        cout << endl;
    }

    int r2, c2;
    cout << "Enter the rows and columns of your array2: ";
    cin >> r2;
    cin >> c2;

    int arr2[r2][c2];
    cout << "Enter the elements of your array2: ";
    for (int i = 0; i < r2; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            cin >> arr2[i][j];
        }
    }
    cout << "Your second array is: " << endl;
    for (int i = 0; i < r2; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            cout << arr2[i][j] << " ";
        }
        cout << endl;
    }

    // arr1[r1][c1] *arr2[r2][c2]
    if (c1 != r2)
    {
        cout << "Your matrixes cant be multiplied!!";
    }

    int C[r1][c2];

    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            int value = 0;
            for (int k = 0; k < r2; k++)
            {
                value += arr1[i][k] * arr2[k][j];
            }
            C[i][j] = value;
        }
    }
    cout << "Your matrix after multiplication is: " << endl;
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }
}