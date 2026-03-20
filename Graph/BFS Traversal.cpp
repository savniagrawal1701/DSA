#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
  public:
    
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        int vis[V] = {0}; 
        vis[0] = 1; 
        queue<int> q;
        q.push(0); 
        vector<int> bfs; 
        
        while(!q.empty()) {
            int node = q.front();
            q.pop(); 
            bfs.push_back(node); 
            
            for(auto it : adj[node]) {
                if(!vis[it]) {
                    vis[it] = 1; 
                    q.push(it); 
                }
            }
        }
        return bfs; 
    }
};

int main() {
    
    int V = 5;
    vector<int> adj[V];

    
    
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[0].push_back(3);
    adj[2].push_back(4);

    Solution obj;
    vector<int> result = obj.bfsOfGraph(V, adj);

    
    cout << "BFS Traversal starting from node 0: ";
    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
