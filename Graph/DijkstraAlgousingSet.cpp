#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S) {
        set<pair<int, int>> st;
        vector<int> dist(V, 1e9);

        st.insert({0, S});
        dist[S] = 0;

        while (!st.empty()) {
            auto it = *(st.begin());
            int node = it.second;
            int dis = it.first;
            st.erase(it);

            for (auto it : adj[node]) {
                int adjNode = it[0];
                int edgW = it[1];

                if (dis + edgW < dist[adjNode]) {
                    if (dist[adjNode] != 1e9) {
                        st.erase({dist[adjNode], adjNode});
                    }

                    dist[adjNode] = dis + edgW;
                    st.insert({dist[adjNode], adjNode});
                }
            }
        }
        return dist;
    }
};

int main() {
    int V = 3, E = 3, S = 0;
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