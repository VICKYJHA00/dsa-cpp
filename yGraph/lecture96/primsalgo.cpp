#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<climits>
using namespace std;

class Graph {
public:
    unordered_map<int, list<pair<int,int>>> adj;

    void addedge(int u, int v, int weight) {
        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight});
    }

    void prims() {
        int V = adj.size();

        vector<int> key(V, INT_MAX);
        vector<bool> mst(V, false);
        vector<int> parent(V, -1);

        key[0] = 0;

        for (int count = 0; count < V - 1; count++) {
            int mini = INT_MAX;
            int u = -1;

            // pick minimum key vertex
            for (int v = 0; v < V; v++) {
                if (!mst[v] && key[v] < mini) {
                    mini = key[v];
                    u = v;
                }
            }

            if (u == -1) break; // safety

            mst[u] = true;

            // relax adjacent vertices
            for (auto neighbour : adj[u]) {
                int v = neighbour.first;
                int weight = neighbour.second;

                if (!mst[v] && weight < key[v]) {
                    key[v] = weight;
                    parent[v] = u;
                }
            }
        }

        cout << "Edges in MST:\n";
        for (int i = 1; i < V; i++) {
            cout << parent[i] << " - " << i
                 << "  weight: " << key[i] << endl;
        }
    }
};

int main() {
    Graph g;
    g.addedge(0,1,2);
    g.addedge(0,3,6);
    g.addedge(1,2,3);
    g.addedge(1,3,8);
    g.addedge(1,4,5);
    g.addedge(2,4,7);
    g.addedge(3,4,9);

    g.prims();
    return 0;
}
