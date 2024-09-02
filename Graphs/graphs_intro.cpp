#include <iostream>
#include <list>
#include <vector>
#include <unordered_map>

using namespace std;

vector<vector<int>> PrintADJ(int n, int m, vector<vector<int>> &edges)
{
    vector<int> ans[n];
    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        ans[u].push_back(v);
        ans[v].push_back(u);
    }

    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++)
    {
        adj[i].push_back(i);

        for (int j = 0; j < ans[i].size(); j++)
        {
            adj[i].push_back(ans[i][j]);
        }
    }
    return adj;
}

int main()
{
    int a, b;
    cout << "Enter the number of nodes: ";
    cin >> a;
    cout << "enter the number of edges: ";
    cin >> b;

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

    cout << PrintADJ(a, b, vec);
     
    return 0;
}