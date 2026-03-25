
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<int>> &grid, int delrow[], int delcol[])
    {

        vis[row][col] = 1;

        int n = grid.size(), m = grid[0].size();

        for (int k = 0; k < 4; k++)
        {

            int nrow = row + delrow[k], ncol = col + delcol[k];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == 1)
            {

                dfs(nrow, ncol, vis, grid, delrow, delcol);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n =grid.size();
        int m =grid[0].size();
     if (n == 0 || m == 0)
            return 0;

        int delrow[4] = {-1, 0, 1, 0};
        int delcol[4] = {0, 1, 0, -1};

        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int j = 0; j < m; j++)
        {

            if (!vis[0][j] &&  grid[0][j] == 1)
                dfs(0, j, vis,  grid, delrow, delcol);

            if (!vis[n - 1][j] &&  grid[n - 1][j] == 1)
                dfs(n - 1, j, vis,  grid, delrow, delcol);
        }

        for (int i = 0; i < n; i++)
        {

            if (!vis[i][0] && grid[i][0] == 1)
                dfs(i, 0, vis, grid, delrow, delcol);

            if (!vis[i][m - 1] && grid[i][m - 1] == 1)
                dfs(i, m - 1, vis, grid, delrow, delcol);
        }
int cnt=0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {

                if (!vis[i][j] && grid[i][j] == 1)
                  cnt++;
            }
        }

        return cnt;
    }
};
int main() {
    // Define the grid
    vector<vector<int>> grid{
        {0, 0, 0, 0},
        {1, 0, 1, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0}
    };

    // Create Solution instance
    Solution obj;

    // Compute and print the number of enclaves
    cout << obj.numEnclaves(grid) << endl; // Expected: 3
    return 0;
}