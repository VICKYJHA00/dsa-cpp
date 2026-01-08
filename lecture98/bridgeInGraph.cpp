#include <bits/stdc++.h> // for include all standard headers
using namespace std;
// Tarjan's Algorithm to find bridges in an undirected graph

class Solution {
public:
    vector<vector<int>> bridges;
    vector<int> disc, low, parent;
    int timer = 0;

    void dfs(int u, vector<vector<int>>& adj) {
        disc[u] = low[u] = timer++;

        for (int v : adj[u]) {
            if (disc[v] == -1) {        // not visited
                parent[v] = u;
                dfs(v, adj);

                low[u] = min(low[u], low[v]);

                // bridge condition
                if (low[v] > disc[u]) {
                    bridges.push_back({u, v});
                }
            }
            else if (v != parent[u]) { // back edge
                low[u] = min(low[u], disc[v]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for (auto &e : connections) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        disc.assign(n, -1);
        low.assign(n, -1);
        parent.assign(n, -1);

        for (int i = 0; i < n; i++) {
            if (disc[i] == -1) {
                dfs(i, adj);
            }
        }

        return bridges;
    }
};
