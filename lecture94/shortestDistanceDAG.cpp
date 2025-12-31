// shortest distance in directed acyclic graph (DAG);
#include<iostream>
#include<vector>
#include<stack>
#include<limits.h>
#include<unordered_map>
#include<list>
using namespace std;

class Graph{
    public:
    unordered_map<int, list<pair<int,int>>> adj;

    void addEdge(int u, int v, int weight){
        pair<int,int> p = make_pair(v, weight);
        adj[u].push_back(p);
    }

    void printAdj(){
        for(auto i: adj){
            cout<<i.first<<"->";
            for(auto j : i.second){
                cout<<"("<<j.first<<","<<j.second<<")";
            }cout<<endl;
        }
    }

    void dfs(int node, unordered_map<int,bool> &visited,stack<int> &s){
        visited[node] = true;
        for(auto neighbour : adj[node]){
             if(!visited[neighbour.first]){
                dfs(neighbour.first,visited,s);
             }
        }

        s.push(node);
    }


    void shortestPath(int src, vector<int> &distance, stack<int> &s){
        distance[src] = 0;
        
        while(!s.empty()){
            int top = s.top();
            s.pop();

            if(distance[top] != INT_MAX){
                for(auto i : adj[top]){
                    if(distance[top] + i.second< distance[i.first]){
                        distance[i.first] = distance[top] + i.second;
                    }
                }
            }
        }
    }

};

int main(){
    Graph g;
    g.addEdge(0,1,5);
    g.addEdge(0,2,3);
    g.addEdge(1,2,2);
    g.addEdge(1,3,6);
    g.addEdge(2,3,7);
    g.addEdge(2,4,4);
    g.addEdge(2,5,2);
    g.addEdge(3,4,-1);
    g.addEdge(4,5,-2);

    g.printAdj();

    unordered_map<int,bool> visited;
    stack<int> s;
    int n = 6; // number of nodes
    for(int i =0; i<n; i++){
        if(!visited[i]){
            g.dfs(i,visited,s);
        }
    }

    vector<int> distance(n,INT_MAX);
    int src = 1;
    g.shortestPath(src,distance,s);

    for(int i = 0;i<distance.size();i++){
        if(distance[i] == INT_MAX){
            cout<<"Distance of "<<i<<"from source is: "<<"INF"<<endl;
        }
        else{
            cout<<"Distance of "<<i<<"from source is: "<<distance[i]<<endl;
        }
    }
}