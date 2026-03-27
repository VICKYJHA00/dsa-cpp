// shortest path in an undirected graph using bfs
#include<iostream>
#include<queue>
#include<unordered_map>
#include<list>
#include<vector>
#include<algorithm>
using namespace std;

class graph{
    public:
    unordered_map<int,list<int>> adj;
    void addEdge(int u,int v,bool direction){
        adj[u].push_back(v);
        if(direction){
            adj[v].push_back(u);
        }
    }
    void shortestpath(int src,int dest){
        unordered_map<int,bool>visited;
        unordered_map<int,int> parent;
        queue<int>q;
        q.push(src);
        parent[src] = -1;
        visited[src] = true;

        while(!q.empty()){
            int front = q.front();
            q.pop();
            for(auto i : adj[front]){
                if(!visited[i]){
                    visited[i] = true;
                    parent[i] = front;
                    q.push(i);
                }
            }
        }

        // print shortest path
        int curr = dest;
        vector<int> path;
        path.push_back(curr);
        while(curr != src){
            curr = parent[curr];
            path.push_back(curr);
        }

        reverse(path.begin(),path.end());
        for(auto i:path){
            cout<<i<<" ";
        }

    }
};

int main(){
    graph g;
    g.addEdge(1,2,0);
    g.addEdge(1,3,0);
    g.addEdge(1,4,0);
    g.addEdge(2,5,0);
    g.addEdge(3,8,0);
    g.addEdge(4,6,0);
    g.addEdge(5,8,0);
    g.addEdge(6,7,0);
    g.addEdge(7,8,0);
    g.shortestpath(1,8);
    return 0;
}