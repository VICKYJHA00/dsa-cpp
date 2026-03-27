//cycle detection in an undirected graph using BFS
// it is similar to  kahn's algorith for topological sorting using BFS
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


    
    // detect cycle
    bool CycleDetection(int v){
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
        int cnt = 0;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            cnt++;

            for(auto neighbour : adj[front]){
                indegree[neighbour]--;
                if(indegree[neighbour] == 0){
                    q.push(neighbour);
                }
            }
        }
        if(cnt == v){
            return false;
        }else return true;
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
    bool ans = g.CycleDetection(v);
   if(ans) cout<<"Cycle is present"<<endl;
   else cout<<"Cycle is not present"<<endl;
}