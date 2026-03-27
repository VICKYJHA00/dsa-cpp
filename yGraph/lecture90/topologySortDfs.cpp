// topology sort using DFS
//Topological sort is a linear ordering of vertices in a Directed Acyclic Graph (DAG) such that
// for every directed edge u → v, u appears before v in the ordering.

#include<iostream>
#include<stack>
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
            for(auto j :i.second){
                cout<<j<<" ";
            }
        }
    }

    void dfsTopologicalSort(int node,unordered_map<int,bool> &visited,stack<int> &s){
        visited[node] = true;

        for(auto neighbour : adj[node]){
            if(!visited[neighbour]){
                dfsTopologicalSort(neighbour,visited,s);
            }
        }

        s.push(node);
    }
};

int main(){
    graph g;
    g.addedge(0,1,1);
    g.addedge(0,2,1);
    g.addedge(1,3,1);
    g.addedge(2,3,1);
    g.addedge(3,4,1);
    g.print();
    cout<<endl;
    unordered_map<int,bool>visited;
    stack<int>s;
    for(int i = 0;i<5;i++){
        int node = i;
        if(!visited[node]){
            g.dfsTopologicalSort(node,visited,s);
        }
    }

    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}