// articualationPoint  if we remove a node that create more than one component in a graph is articulation point
#include <iostream>
#include<vector>
#include<list>
#include<unordered_map>
#include<algorithm>
using namespace std; 

class graph{
    public:
    unordered_map<int,list<int>>adj;
    void addedge(int u,int v,bool direction){
        adj[u].push_back(v);
        if(direction == 0){
            adj[v].push_back(u);
        }
    }

    void print(){
        for(auto i : adj){
            cout<<i.first<<"->";
            for(auto j :i.second){
                cout<<j<<" ";
            }
        }
    }

    void dfs(int node,int parent,unordered_map<int,bool> &visited,vector<int> &disc, vector<int> &low,int timer,unordered_map<int,bool> &ap){
        visited[node] = true;
        disc[node] = low[node] = timer++;
        int child = 0;

        for(auto neighbour : adj[node]){
            if(neighbour == parent) continue;

            if(!visited[neighbour]){
                dfs(neighbour,node,visited,disc,low,timer,ap);
                low[node] = min(low[node],low[neighbour]);
                // AP point condition
                if(low[neighbour] >= disc[node] && parent != -1){
                    ap[node]  = true;
                }
                child++;
            }else{
                // back edge
                low[node] = min(low[node],disc[neighbour]);
            }
        }

        if(parent == -1 && child > 1 ) ap[node] = true;
    }


    
};

int main(){
    graph g;
    g.addedge(0,1,0);
    g.addedge(1,2,0);
    g.addedge(0,3,0);
    g.addedge(3,4,0);
    g.addedge(0,4,0);

    vector<int> disc(5,-1);
    vector<int> low(5,-1);
    unordered_map<int,bool> visited;
    unordered_map<int,bool> ap;
    int timer = 0;
    g.dfs(0,-1,visited,disc,low,timer,ap);
    for(int i = 0;i<5;i++){
        if(ap[i] == true){
            cout<<i<<" ";
        }
    }
}