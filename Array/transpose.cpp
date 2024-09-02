#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    int array[n][m];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> array[i][j];
        }
    }

    cout << "Your matrix will be: "<<endl;
        // output each array element’s value
        for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
    
    int trans[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            trans[i][j] = array[j][i];
        }
    }
    cout << "The tranpose of your matrix will be: " <<endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << trans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}