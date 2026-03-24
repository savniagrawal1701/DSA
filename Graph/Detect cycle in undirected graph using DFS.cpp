#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    bool dfs(int node, int parent, int vis[], vector<int> adj[]) {
        vis[node] = 1;
        for (auto adjacentNode : adj[node]) {
            if (!vis[adjacentNode]) {
                if (dfs(adjacentNode, node, vis, adj)) return true;
            } else if (adjacentNode != parent) {
                return true;
            }
        }
        return false;
    }

public:
    bool isCycle(int V, vector<int> adj[]) {
        int vis[V];
        for (int i = 0; i < V; i++) vis[i] = 0;

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (dfs(i, -1, vis, adj)) return true;
            }
        }
        return false;
    }
};

int main() {
   
    int V = 5;
    vector<int> adj[V];

    adj[1].push_back(2);
    adj[2].push_back(1);

    adj[2].push_back(3);
    adj[3].push_back(2);

    adj[3].push_back(4);
    adj[4].push_back(3);

    adj[4].push_back(2);
    adj[2].push_back(4);

    Solution obj;
    bool hasCycle = obj.isCycle(V, adj);

    if (hasCycle) {
        cout << "Cycle Detected in the graph." << endl;
    } else {
        cout << "No Cycle detected in the graph." << endl;
    }

    return 0;
}
