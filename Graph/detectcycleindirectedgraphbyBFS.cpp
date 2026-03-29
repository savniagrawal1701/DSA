#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    
    bool hasCycle(int V, vector<int> adj[]) {
        
        vector<int> indegree(V, 0);
        
        
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
        
        
        int count=0;
        
        
        while (!q.empty()) {
            
            int node = q.front();
            q.pop();
            
            
          count++;
            
            
            for (auto it : adj[node]) {
                indegree[it]--;
                
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }
        
        
        if(count==V) return false;
        return true;
    }
};


int main() {
      int V = 6, E = 6;
    
    
    vector<int> adj[V];
    
    
    adj[5].push_back(0);
    adj[5].push_back(2);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);
    


    Solution obj;
    if (obj.hasCycle(V, adj))
        cout << "Cycle detected\n";
    else
        cout << "No cycle\n";
    return 0;
}