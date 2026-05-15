#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
private:
    void dfs(int node, vector<int>& vis, vector<int> adj[], stack<int>& st) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs(it, vis, adj, st);
            }
        }
        st.push(node);
    }

    void dfs3(int node, vector<int>& vis, vector<int> adjT[]) {
        vis[node] = 1;
        for (auto it : adjT[node]) {
            if (!vis[it]) {
                dfs3(it, vis, adjT);
            }
        }
    }

public:
    int kosaraju(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);
        stack<int> st;
        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                dfs(i, vis, adj, st);
            }
        }

        vector<int> adjT[V];
        for(int i = 0; i < V; i++) {
            vis[i] = 0;
            for(auto it : adj[i]) {
                adjT[it].push_back(i);
            }
        }

        int scc = 0;
        while(!st.empty()) {
            int node = st.top();
            st.pop();
            if(!vis[node]) {
                scc++;
                dfs3(node, vis, adjT);
            }
        }
        return scc;
    }
};

int main() {
    int V = 5;
    vector<int> adj[5];
    
    adj[0].push_back(2);
    adj[2].push_back(1);
    adj[1].push_back(0);
    adj[0].push_back(3);
    adj[3].push_back(4);

    Solution sol;
    cout << sol.kosaraju(V, adj) << "\n";

    return 0;
}
