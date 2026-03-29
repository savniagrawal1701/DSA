#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> findOrder(int V, vector<vector<int>>& prerequisites) {
         
        vector<int> adj[V];
        for (auto it : prerequisites) {
            adj[it[1]].push_back(it[0]);
        }
        
        int indegree[V] = {0};
        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                indegree[it]++;
            }
        }
        
        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        
        vector<int> topo;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        
        if (topo.size() == V) return topo;
        return {}; 
    }
};

int main() {
    int V = 4;
    
    vector<vector<int>> prerequisites = {{1, 0}, {2, 1}, {3, 2}};

    Solution sol;
    vector<int> result = sol.findOrder(V, prerequisites);

    if (result.empty()) {
        cout << "No valid order possible (Cycle detected)." << endl;
    } else {
        cout << "Valid task order: ";
        for (int task : result) {
            cout << task << " ";
        }
        cout << endl;
    }

    return 0;
}
