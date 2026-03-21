#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void dfs(int node, vector<int> adjList[], int visited[])
    {

        visited[node] = 1;

        for (auto neighbor : adjList[node])
        {
            if (!visited[neighbor])
            {
                dfs(neighbor, adjList, visited);
            }
        }
    }

public:
    int numProvinces(vector<vector<int>> adj, int V)
    {

        vector<int> adjList[V];

        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {

                if (adj[i][j] == 1 && i != j)
                {
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }

        int visited[V] = {0};

        int count = 0;

        for (int i = 0; i < V; i++)
        {

            if (!visited[i])
            {

                count++;
                dfs(i, adjList, visited);
            }
        }

        return count;
    }
};

int main()
{

    vector<vector<int>> adj = {
        {1, 0, 1},
        {0, 1, 0},
        {1, 0, 1}};

    int V = 3;

    Solution obj;

    cout << obj.numProvinces(adj, V) << endl;

    return 0;
}