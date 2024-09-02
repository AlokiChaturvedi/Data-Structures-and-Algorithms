#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>

using namespace std;

void BFS(int G[][7], int start, int n)
{
    int i = start, j;
    queue<int> q;
    int visited[7] = {0};
    cout << i << " ";
    visited[i] = 1;
    q.push(i);

    while (!q.empty())
    {
        int front=q.front();
        q.pop();
        i=q.back();

        for (j = 1; j < n; j++)
        {
            if (G[i][j] == 1 && visited[j] == 0)
            {
                cout << j << " ";
                visited[j] = 1;
                q.push(j);
            }
        }
    }
}

void DFS(int G[][7], int start, int n)
{
    int visited[7] = {0};
    int j;
    if (visited[start] == 0)
    {
        cout << start << ", ";
        visited[start] = 1;
        for (j = 1; j < n; j++)
        {
            if (G[start][j] == 1 && visited[j] == 0)
            {
                DFS(G, j, n);
            }
        }
    }
}

int main()
{

    int G[7][7] = {
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 1, 0, 0, 0},
        {0, 1, 0, 0, 1, 0, 0},
        {0, 1, 0, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0},
    };

    BFS(G, 1, 7);

    return 0;
}