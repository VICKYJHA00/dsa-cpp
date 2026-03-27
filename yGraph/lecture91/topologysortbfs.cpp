// kahn's algorith for topological sorting using BFS
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<list>
#include<iostream>
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
        for(auto i:adj){
            cout<<i.first<<"->";
            for(auto j :i.second){
                cout<<j<<" ";
            }
        }
    }

    // count vertices
    int countVertices() {
    unordered_set<int> nodes;

    for (auto &i : adj) {
        nodes.insert(i.first);
        for (auto &j : i.second) {
            nodes.insert(j);
        }
    }
    return nodes.size();
}


    
    // find all indregrees
    vector<int> topologicalSort(int v){
        // indegree array
        vector<int>indegree(v,0);
        for(auto i : adj){
            for(auto j : i.second){
                indegree[j]++;
            }
        }

        queue<int> q;
        for(int i = 0;i<v;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        // bfs
        vector<int> ans;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            ans.push_back(front);

            for(auto neighbour : adj[front]){
                indegree[neighbour]--;
                if(indegree[neighbour] == 0){
                    q.push(neighbour);
                }
            }
        }
        return ans;
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
    int v = g.countVertices();
    vector<int> ans = g.topologicalSort(v);
    for(auto i : ans){
        cout<<i<<" ";
    }
}