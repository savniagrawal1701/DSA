#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int CheapestFLight(int n, vector<vector<int>> &flights, int src, int dst, int K)
    {

        vector<pair<int, int>> adj[n];
        for (auto it : flights)
        {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        priority_queue<pair<int, int>,
                       vector<pair<int, int>>, greater<pair<int, int>>>
            pq;

        vector<int> dist(n, INT_MAX), ways(n, 0);

        dist[src] = 0;

        ways[src] = 1;

        pq.push({0, src});

        int mod = (int)(1e9 + 7);

        while (!pq.empty())
        {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto it : adj[node])
            {

                int adjNode = it.first;

                int edW = it.second;

                if (dis + edW < dist[adjNode])
                {

                    dist[adjNode] = dis + edW;

                    pq.push({dis + edW, adjNode});

                    ways[adjNode] = ways[node];
                }

                else if (dis + edW == dist[adjNode])
                {

                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }

        return ways[dst] % mod;
    }
};

int main()
{

    int n = 7;

    vector<vector<int>> edges = {{0, 1, 2}, {0, 1, 2}, {1, 1, 3}, {1, 2, 3}, {1, 3, 3}, {3, 2, 1}, {1, 3, 1}, {2, 5, 1}, {0, 4, 5}, {4, 6, 2}};

    Solution obj;

    int ans = obj.CheapestFLight(n, edges, 0, 3, 1);

    cout << ans << endl;

    return 0;
}
