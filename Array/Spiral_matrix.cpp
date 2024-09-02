#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void spiralMatrix(vector<vector<int>> &vec)
{

    int left = 0;
    int right = vec[0].size() - 1;
    int top = 0;
    int bottom = vec.size() - 1;

    int direction = 0;

    while (left<=right &&  top<=bottom)
    {
        // 1.left to right
        if (direction == 0)
        {
            for (int col = left; col <= right; col++)
            {
                cout << vec[top][col] << " ";
            }
            top++;
        }

        // 2.top to bottom
        else if (direction == 1)
        {
            for (int row = top; row <= bottom; row++)
            {
                cout << vec[row][right] << " ";
            }
            right--;
        }

        // 3.right to left
        else if (direction == 2)
        {
            for (int col = right; col >= left; col--)
            {
                cout << vec[bottom][col] << " ";
            }
            bottom--;
        }

        // 4.bottom to top
        else
        {
            for (int row = bottom; row >= top; row--)
            {
                cout << vec[row][left] << " ";
            }
            left++;
        }

        direction=(direction+1)%4;
    }
}

int main()
{
    int m, n;
    cout << "Enter the number of rows and columns: ";
    cin >> n >> m;

    vector<vector<int>> vec(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> vec[i][j];
        }
    }

    spiralMatrix(vec);

    return 0;
}