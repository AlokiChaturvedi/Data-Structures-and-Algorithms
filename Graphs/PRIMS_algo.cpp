#include <iostream>
#define V 8
#define I 32767

using namespace std;
 
void PrintMST(int T[][V-2], int G[V][V]){
    cout << "\nMinimum Spanning Tree Edges (w/ cost)\n" << endl;
    int sum {0};
    for (int i {0}; i<V-2; i++){
        int c = G[T[0][i]][T[1][i]];
        cout << "[" << T[0][i] << "]---[" << T[1][i] << "] cost: " << c << endl;
        sum += c;
    }
    cout << endl;
    cout << "Total cost of MST: " << sum << endl;
}
 
void PrimsMST(int G[V][V], int n){
    int u;
    int v;
    int min {I};
    int track [V];
    int T[2][V-2] {0};
 
    // Initial: Find min cost edge
    for (int i {1}; i<V; i++){
        track[i] = I;  // Initialize track array with INFINITY
        for (int j {i}; j<V; j++){
            if (G[i][j] < min){
                min = G[i][j];
                u = i;
                v = j;
            }
        }
    }
    T[0][0] = u;
    T[1][0] = v;
    track[u] = track[v] = 0;
 
    // Initialize track array to track min cost edges
    for (int i {1}; i<V; i++){
        if (track[i] != 0){
            if (G[i][u] < G[i][v]){
                track[i] = u;
            } else {
                track[i] = v;
            }
        }
    }
 
    // Repeat
    for (int i {1}; i<n-1; i++){
        int k;
        min = I;
        for (int j {1}; j<V; j++){
            if (track[j] != 0 && G[j][track[j]] < min){
                k = j;
                min = G[j][track[j]];
            }
        }
        T[0][i] = k;
        T[1][i] = track[k];
        track[k] = 0;
 
        // Update track array to track min cost edges
        for (int j {1}; j<V; j++){
            if (track[j] != 0 && G[j][k] < G[j][track[j]]){
                track[j] = k;
            }
        }
    }
    PrintMST(T, G);
}
 
int main() {
 
    int cost [V][V] {
            {I, I, I, I, I, I, I, I},
            {I, I, 25, I, I, I, 5, I},
            {I, 25, I, 12, I, I, I, 10},
            {I, I, 12, I, 8, I, I, I},
            {I, I, I, 8, I, 16, I, 14},
            {I, I, I, I, 16, I, 20, 18},
            {I, 5, I, I, I, 20, I, I},
            {I, I, 10, I, 14, 18, I, I},
    };
 
    int n = sizeof(cost[0])/sizeof(cost[0][0]) - 1;
 
    PrimsMST(cost, n);
 
    return 0;
}


// // A C++ program for Prim's Minimum
// // Spanning Tree (MST) algorithm. The program is
// // for adjacency matrix representation of the graph

// #include <bits/stdc++.h>
// using namespace std;

// // Number of vertices in the graph
// #define V 5

// // A utility function to find the vertex with
// // minimum key value, from the set of vertices
// // not yet included in MST
// int minKey(int key[], bool mstSet[])
// {
//     // Initialize min value
//     int min = INT_MAX, min_index;

//     for (int v = 0; v < V; v++)
//         if (mstSet[v] == false && key[v] < min)
//             min = key[v], min_index = v;

//     return min_index;
// }

// // A utility function to print the
// // constructed MST stored in parent[]
// void printMST(int parent[], int graph[V][V])
// {
//     cout << "Edge \tWeight\n";
//     for (int i = 1; i < V; i++)
//         cout << parent[i] << " - " << i << " \t"
//              << graph[i][parent[i]] << " \n";
// }

// // Function to construct and print MST for
// // a graph represented using adjacency
// // matrix representation
// void primMST(int graph[V][V])
// {
//     // Array to store constructed MST
//     int parent[V];

//     // Key values used to pick minimum weight edge in cut
//     int key[V];

//     // To represent set of vertices included in MST
//     bool mstSet[V];

//     // Initialize all keys as INFINITE
//     for (int i = 0; i < V; i++)
//         key[i] = INT_MAX, mstSet[i] = false;

//     // Always include first 1st vertex in MST.
//     // Make key 0 so that this vertex is picked as first
//     // vertex.
//     key[0] = 0;

//     // First node is always root of MST
//     parent[0] = -1;

//     // The MST will have V vertices
//     for (int count = 0; count < V - 1; count++)
//     {

//         // Pick the minimum key vertex from the
//         // set of vertices not yet included in MST
//         int u = minKey(key, mstSet);

//         // Add the picked vertex to the MST Set
//         mstSet[u] = true;

//         // Update key value and parent index of
//         // the adjacent vertices of the picked vertex.
//         // Consider only those vertices which are not
//         // yet included in MST
//         for (int v = 0; v < V; v++)

//             // graph[u][v] is non zero only for adjacent
//             // vertices of m mstSet[v] is false for vertices
//             // not yet included in MST Update the key only
//             // if graph[u][v] is smaller than key[v]
//             if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
//                 parent[v] = u, key[v] = graph[u][v];
//     }

//     // Print the constructed MST
//     printMST(parent, graph);
// }

// // Driver's code
// int main()
// {
//     int graph[V][V] = {{0, 2, 0, 6, 0},
//                        {2, 0, 3, 8, 5},
//                        {0, 3, 0, 0, 7},
//                        {6, 8, 0, 0, 9},
//                        {0, 5, 7, 9, 0}};

//     // Print the solution
//     primMST(graph);

//     return 0;
// }

// // This code is contributed by rathbhupendra
