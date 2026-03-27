#include<iostream>
#include<queue>
#include<stack>
#include<unordered_map>
#include<list>
using namespace std;

class graph{
    public:
    unordered_map<int,list<int>> adj;
    // int src = 3;

    void addEdge(int u,int v,bool direction){
        adj[u].push_back(v);
        if(direction == 0){
            adj[v].push_back(u);
        }
    }

    void print(){
        for(auto i:adj){
            cout<<i.first<<"->";
            for(auto j:i.second){
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }

    void dfs(int src){
        stack<int>s;
        unordered_map<int,bool> visited;
        s.push(src);
        visited[src] = true;
        while(!s.empty()){
            int top = s.top();
            s.pop();
            cout<<top<<" ";
            for(auto i: adj[top]){
                if(!visited[i]){
                    visited[i] = true;
                    s.push(i);
                    
                }
            }
        }
    }

    // void bfs(int src){
    //     queue<int> q;
    //     unordered_map<int,bool> visited;
    //     q.push(src);
    //     visited[src] = true;
    //     while(!q.empty()){
    //         int front = q.front();
    //         q.pop();
    //         cout<<front<<" ";
    //         for(auto i: adj[front]){
    //             if(!visited[i]){
    //                 q.push(i);
    //                 visited[i] = true;
    //             }
    //         }
    //     }
    // }

};

int main(){
    graph g;
    g.addEdge(0,1,0);
    g.addEdge(0,4,0);
    g.addEdge(1,2,0);
    g.addEdge(1,3,0);
    g.print();
    cout<<"DFS Traversal:"<<endl;
    g.dfs(0);
}