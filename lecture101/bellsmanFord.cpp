#include<iostream>
#include<stack>
#include<unordered_map>
#include<list>
#include<vector>
using namespace std;

int bellsmanFord(int n , int src, int dest,vector<vector<int>> &edges){
    vector<int> dist(n+1,1e9);
    dist[src] = 0;
    for(int i =1;i<= n-1;i++){
        for(int j = 0;j<edges.size();j++){
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];
            if(dist[u] != 1e9 && dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
            }
        }
    }

    // check for negative weight cycle
    bool negativeCycle = false;
    for(int j = 0;j<edges.size();j++){
        int u = edges[j][0];
        int v = edges[j][1];
        int w = edges[j][2];
        if(dist[u] != 1e9 && dist[u] + w < dist[v]){
            negativeCycle = true;
            break;
        }
    }

    if(negativeCycle) return -1;

    return dist[dest];

}

int main(){
    vector<vector<int>> edges;
    edges.push_back({0,1, -1});
    edges.push_back({0,2,4});
    edges.push_back({1,2,3});
    edges.push_back({1,3,2});
    edges.push_back({1,4,2});
    edges.push_back({3,2,5});
    edges.push_back({3,1,1});
    edges.push_back({4,3,-3});
    int n = 5;
    int src = 0;
    int dest = 3;
    int ans = bellsmanFord(n,src,dest,edges);

    cout<<"Shortest path from "<<src<<" to "<<dest<<" is: "<<ans<<endl;
    return 0;
}