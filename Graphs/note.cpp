#include <iostream>
using namespace std;

int main(){

    int n,m;
    cout<<"Enter the number of nodes and edge: ";
    cin>>n>>m;

    int adj[n][m];
    cout<<"Enter the elements of the matrix: ";
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u][v]=1;
        adj[v][u]=1;
    }
    
}