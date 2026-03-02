#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m; // n nodes, m edges
    cin >> n >> m;
    
    // Array of vectors
    vector<int> adj[n + 1];
    
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // Remove this for directed graph
    }
    return 0;
}
