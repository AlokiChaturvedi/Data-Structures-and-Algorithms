#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void matrixRotation(vector<vector<int>> &vec)
{

    int n = vec.size();
    // transpose
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            swap(vec[i][j], vec[j][i]);
        }
    }
    // reverse
    for (int i = 0; i < n; i++)
    {
        reverse(vec[i].begin(), vec[i].end());
    }
}

int main()
{

    int n;
    cout << "Enter the number of rows of matrix: ";
    cin >> n;

    vector<vector<int>> vec(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> vec[i][j];
        }
    }

    cout << "Your matrix is: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }

    matrixRotation(vec);

    cout << "Your matrix after 90* degree rotation: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}