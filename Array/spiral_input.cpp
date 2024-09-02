#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void vectorInput(vector<vector<int>> &vec)
{
    int left = 0;
    int right = vec[0].size() - 1;
    int top = 0;
    int bottom = vec.size() - 1;

    int direction = 0;
    int value = 1;
    while (left <= right && top <= bottom)
    {
        // 1.left to right
        if (direction == 0)
        {
            for (int col = left; col <= right; col++)
            {
                vec[top][col] = value++;
            }
            top++;
        }

        // 2.top to bottom
        else if (direction == 1)
        {
            for (int row = top; row <= bottom; row++)
            {
                vec[row][right] = value++;
            }
            right--;
        }

        // 3.right to left
        else if (direction == 2)
        {
            for (int col = right; col >= left; col--)
            {
                vec[bottom][col] = value++;
            }
            bottom--;
        }

        // 4.bottom to top
        else
        {
            for (int row = bottom; row >= top; row--)
            {
                vec[row][left] = value++;
            }
            left++;
        }

        direction = (direction + 1) % 4;
    }
}

int main()
{
    int n;
    cout<<"Enter the size of the matrix: ";
    cin>>n;
    vector<vector<int>> vec(n, vector<int>(n));

    vectorInput(vec);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << vec[i][j]<<" ";
        }
        cout << endl;
    }

    return 0;
}