#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// Disjoint Set Data Structure
class DisjointSet {
public:
    vector<int> parent, size, rank;
    
    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        rank.resize(n + 1, 0);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    // Find Ultimate Parent with Path Compression
    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    // Union by Rank (included as it was declared in your snippet)
    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        } else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        } else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    // Union by Size (used in your snippet)
    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        
        if (ulp_u == ulp_v) return;
        
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    int maxRemove(vector<vector<int>>& stones, int n) {
        int maxRow = 0;
        int maxCol = 0;
        
        // Find the maximum row and column indices
        for(auto it : stones) {
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }
        
        // Initialize DSU. Total nodes = maxRow + maxCol + 1 (to accommodate 0-based indexing)
        DisjointSet ds(maxRow + maxCol + 1);
        unordered_map<int, int> stoneNodes;
        
        // Connect row nodes and column nodes
        for(auto it : stones) {
            int nodeRow = it[0];
            // Shift column index to avoid collision with row indices
            int nodeCol = it[1] + maxRow + 1; 
            
            ds.unionBySize(nodeRow, nodeCol);
            stoneNodes[nodeRow] = 1;
            stoneNodes[nodeCol] = 1;
        }
        
        int cnt = 0;
        // Count the number of connected components
        for(auto it : stoneNodes) {
            if(ds.findUPar(it.first) == it.first) {
                cnt++;
            }
        }
        
        // The maximum stones we can remove is Total Stones - Number of Components
        return n - cnt;
    }
};

int main() {
    Solution sol;
    
    // Example test case:
    // Stones at: (0,0), (0,1), (1,0), (1,2), (2,1), (2,2)
    vector<vector<int>> stones = {
        {0, 0}, {0, 1}, {1, 0}, {1, 2}, {2, 1}, {2, 2}
    };
    int n = stones.size();
    
    cout << "Maximum number of stones that can be removed: " << sol.maxRemove(stones, n) << endl;
    // Expected output: 5
    
    return 0;
}
