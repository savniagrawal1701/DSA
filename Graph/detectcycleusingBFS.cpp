#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
private:
    
    bool detect(int src, vector<int> adj[], int vis[]) {
        vis[src] = 1;
        
        queue<pair<int, int>> q;
        q.push({src, -1});

        while (!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for (auto adjacentNode : adj[node]) {
                if (!vis[adjacentNode]) {
                    vis[adjacentNode] = 1;
                    q.push({adjacentNode, node});
                }
                
                else if (parent != adjacentNode) {
                    return true;
                }
            }
        }
        return false;
    }

public:
    
    bool isCycle(int V, vector<int> adj[]) {
        int vis[V] = {0};
        
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (detect(i, adj, vis)) return true;
            }
        }
        return false;
    }
};

int main() {
    
    int V = 4;
    vector<int> adj[V];

    
    adj[0].push_back(1);
    adj[1].push_back(0);

    adj[1].push_back(2);
    adj[2].push_back(1);

    adj[2].push_back(0);
    adj[0].push_back(2);

    adj[2].push_back(3);
    adj[3].push_back(2);

    Solution obj;
    bool ans = obj.isCycle(V, adj);

    if (ans)
        cout << "Cycle Detected" << endl;
    else
        cout << "No Cycle Detected" << endl;

    return 0;
}