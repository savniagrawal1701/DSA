#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool isPossible(int N, vector<pair<int, int>>& prerequisites) {
        
        vector<int> adj[N];
        for (auto it : prerequisites) {
            adj[it.first].push_back(it.second);
        }

        
        vector<int> indegree(N, 0);
        for (int i = 0; i < N; i++) {
            for (auto it : adj[i]) {
                indegree[it]++;
            }
        }

        
        queue<int> q;
        for (int i = 0; i < N; i++) {
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

        
        if (topo.size() == N) return true;
        return false;
    }
};

int main() {
    int N = 4;
    vector<pair<int, int>> prerequisites = {{1, 0}, {2, 1}, {3, 2}};

    Solution sol;
    if (sol.isPossible(N, prerequisites)) {
        cout << "Possible to finish all tasks" << endl;
    } else {
        cout << "Impossible to finish all tasks (Cycle detected)" << endl;
    }

    return 0;
}