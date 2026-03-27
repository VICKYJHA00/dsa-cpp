#include<iostream>
#include<queue>
#include<unordered_map>
#include<list>
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
            for(auto j : i.second){
                cout<<j<<" ";
            }
        }
    }


    bool isCycleInDirectedGraph(int node,unordered_map<int,bool>& visited,unordered_map<int,bool>& dfsvisited){
        visited[node] = true;
        dfsvisited[node] = true;

        for(auto neighbour : adj[node]){
            if(!visited[neighbour]){
                if(isCycleInDirectedGraph(neighbour,visited,dfsvisited)){
                    return true;
                }
            }
            else if(dfsvisited[neighbour]){
                return true;
            }
        }

        dfsvisited[node] = false;
        return false;
    }
};

int main(){
    graph g;
    g.addedge(0,1,1);
    g.addedge(1,2,1);
    g.addedge(2,3,1);
    g.addedge(3,1,1);
    g.addedge(3,4,1);
    g.print();
    unordered_map<int,bool> visited;
    unordered_map<int,bool> dfsvisited;
    for(auto i : g.adj){
        int node = i.first;
        if(!visited[node]){
            if(g.isCycleInDirectedGraph(node,visited,dfsvisited)){
                cout<<"Cycle detected in directed graph"<<endl;
                return 0;
            }
        }
    }
}