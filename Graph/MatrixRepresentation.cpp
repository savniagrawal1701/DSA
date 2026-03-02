#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m; // n nodes, m edges
    cin >> n >> m;
    
    // Adjacency Matrix initialized to 0
    vector<vector<int>> adj(n + 1, vector<int>(n + 1, 0));
    
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1; // Remove this for directed graph
    }
    return 0;
}
