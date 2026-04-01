#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(V);
        for (int i = 0; i < V; i++) dist[i] = 1e9;

        dist[S] = 0;
        pq.push({0, S});

        while (!pq.empty()) {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto it : adj[node]) {
                int edgeWeight = it[1];
                int adjNode = it[0];

                if (dis + edgeWeight < dist[adjNode]) {
                    dist[adjNode] = dis + edgeWeight;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        return dist;
    }
};

int main() {
    int V = 3, S = 0;
    vector<vector<int>> adj[V];

    adj[0].push_back({1, 1});
    adj[1].push_back({2, 3});
    adj[0].push_back({2, 6});

    Solution obj;
    vector<int> res = obj.dijkstra(V, adj, S);

    for (int i = 0; i < V; i++) {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}
