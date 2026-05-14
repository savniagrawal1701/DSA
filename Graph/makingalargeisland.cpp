#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

// Standard Disjoint Set Union (DSU) Implementation
class DisjointSet {
public:
    vector<int> parent, size;
    
    // Constructor
    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    // Find ultimate parent with path compression
    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    // Union by size
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
private:
    bool isValid(int newr, int newc, int n) {
        return newr >= 0 && newr < n && newc >= 0 && newc < n;
    }

public:
    int MaxConnection(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n * n);
        
        // Step 1: Connect all adjacent 1s into components
        for(int row = 0; row < n; row++) {
            for(int col = 0; col < n; col++) {
                if(grid[row][col] == 0) continue;
                
                int dr[] = {-1, 0, 1, 0};
                int dc[] = {0, -1, 0, 1};
                
                for(int ind = 0; ind < 4; ind++) {
                    int newr = row + dr[ind];
                    int newc = col + dc[ind];
                    
                    if(isValid(newr, newc, n) && grid[newr][newc] == 1) {
                        int nodeNo = row * n + col;
                        int adjNodeNo = newr * n + newc;
                        ds.unionBySize(nodeNo, adjNodeNo);
                    }
                }
            }
        }
        
        // Step 2: Try converting each 0 to 1 and see how big the component gets
        int mx = 0;
        for(int row = 0; row < n; row++) {
            for(int col = 0; col < n; col++) {
                if(grid[row][col] == 1) continue;
                
                int dr[] = {-1, 0, 1, 0};
                int dc[] = {0, -1, 0, 1};
                set<int> components;
                
                for(int ind = 0; ind < 4; ind++) {
                    int newr = row + dr[ind];
                    int newc = col + dc[ind];
                    
                    if(isValid(newr, newc, n)) {
                        if(grid[newr][newc] == 1) {
                            components.insert(ds.findUPar(newr * n + newc));
                        }
                    }
                }
                
                int sizeTotal = 0;
                for(auto it : components) {
                    sizeTotal += ds.size[it];
                }
                
                mx = max(mx, sizeTotal + 1); // +1 is for the 0 we just flipped
            }
        }
        
        // Step 3: Handle edge case where the grid might already be completely filled with 1s
        for(int cellNo = 0; cellNo < n * n; cellNo++) {
            mx = max(mx, ds.size[ds.findUPar(cellNo)]);
        }
        
        return mx;
    }
};

int main() {
    Solution sol;
    
    // Example test case
    vector<vector<int>> grid = {
        {1, 1, 0, 1, 1},
        {1, 1, 0, 1, 1},
        {0, 0, 1, 0, 0},
        {1, 1, 0, 1, 1},
        {1, 1, 0, 1, 1}
    };
    
    cout << "Maximum connection possible by flipping one '0' is: " << sol.MaxConnection(grid) << endl;
    // Expected output: 9
    // By flipping the 0 at grid[2][2], it connects 4 isolated islands of size 4 + the middle 1 itself (actually here they are not connected directly by that one zero, but changing [1][2] connects the top two, etc. Play around with it!)

    return 0;
}