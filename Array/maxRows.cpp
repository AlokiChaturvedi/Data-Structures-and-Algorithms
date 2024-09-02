#include <iostream>
#include <vector>
#include<climits>
using namespace std;

int maxOnesRow(vector<vector<int>> v)
{
    int maxOnes = INT_MIN;
    int maxRow = -1;
    int column = v[0].size();

    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            int numberofOnes=0;
            if (v[i][j] == 1)
            {
                numberofOnes = column - j;
            }
            if (numberofOnes > maxOnes)
            {
                maxOnes = numberofOnes;
                maxRow = i;
            }
            break;
        }
    }
    return maxRow;
}

int main()
{
    int m, n;
    cin >> n >> m;

    vector<vector<int>> vec(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> vec[i][j];
        }
    }

    int res = maxOnesRow(vec);
    cout << res;
    return 0;
}