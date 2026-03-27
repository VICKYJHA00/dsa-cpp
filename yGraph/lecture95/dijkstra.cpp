// shortest distance in directed acyclic graph (DAG);
#include<iostream>
#include<vector>
#include<stack>
#include<limits.h>
#include<unordered_map>
#include<list>
#include<set>
#include<queue>
using namespace std;

class Graph{
    public:
    unordered_map<int, list<pair<int,int>>> adj;

    void addEdge(int u, int v, int weight , bool direction){
        adj[u].push_back(make_pair(v, weight));
        if(direction == 0 ){
            adj[v].push_back(make_pair(u,weight));
        }
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


void diskstra(Graph& g, int src, vector<int> &distance ){
    distance[src] = 0;

    priority_queue<pair<int,int>, 
                   vector<pair<int,int>>, 
                   greater<pair<int,int>>> pq;

    pq.push(make_pair(0,src));

    while(!pq.empty()){
        auto top = pq.top();
        int NodeDistance = top.first;
        int node = top.second;
        pq.pop();

        if(NodeDistance > distance[node]) continue;

        for(auto neighbour : g.adj[node]){
            int v = neighbour.first;
            int weight = neighbour.second;
            if(distance[node] != INT_MAX && distance[node] + weight < distance[v]){
                distance[v] = distance[node] + weight;
                pq.push(make_pair(distance[v],v));
            }
        }
    }
}

int main(){
    Graph g;
    g.addEdge(0,1,4,0);
    g.addEdge(0,2,1,0);
    g.addEdge(2,1,2,0);
    g.addEdge(1,3,1,0);
    g.addEdge(2,3,5,0);
    int n = 4; // number of nodes

    g.printAdj();

    // unordered_map<int,bool> visited;
    // stack<int> s;
    // int n = 6; // number of nodes
    // for(int i =0; i<n; i++){
    //     if(!visited[i]){
    //         g.dfs(i,visited,s);
    //     }
    // }

    set<pair<int,int>> s; // first for the distance and second for the node
    vector<int> distance(n,INT_MAX);
    int src = 1;

    distance[src] = 0;
    s.insert(make_pair(0,src));

    while(!s.empty()){
        auto top = *(s.begin());
        int nodeDistance = top.first;
        int node = top.second;
        s.erase(s.begin());

        for(auto neighbour : g.adj[node]){
            if(nodeDistance + neighbour.second < distance[neighbour.first]){
                auto record = s.find(make_pair(distance[neighbour.first],neighbour.first));
                if(record != s.end()){
                    s.erase(record);
                }
                distance[neighbour.first] = nodeDistance + neighbour.second;
                s.insert(make_pair(distance[neighbour.first],neighbour.first));
            }
        }

        
    }
    // g.shortestPath(src,distance,s);

    for(int i = 0;i<distance.size();i++){
        if(distance[i] == INT_MAX){
            cout<<"Distance of "<<i<<"from source is: "<<"INF"<<endl;
        }
        else{
            cout<<"Distance of "<<i<<"from source is: "<<distance[i]<<endl;
        }
    }
}
