// kosaraju algorithm to find strongly connected components in a directed graph
#include <iostream>
#include <vector>
#include <list>
#include<stack>
#include<unordered_map>
using namespace std;

class graph{
    public:
    unordered_map<int,list<int>> adj;
    unordered_map<int,list<int>> transpose;
    void addedge(int u,int v){
        adj[u].push_back(v);
        transpose[v].push_back(u);
    }
    void topoSort(int node,stack<int> &st,unordered_map<int,bool> &visited){
        visited[node] = true;
        for(auto nbr : adj[node]){
            if(!visited[nbr]){
                topoSort(nbr,st,visited);
            }
        }
        st.push(node);
    }

    void dfs(int node,unordered_map<int,bool> &visited){
        visited[node] = true;
        cout<<node<<" ";
        for(auto nbr : transpose[node]){
            if(!visited[nbr]){
                dfs(nbr,visited);
            }
        }
    }

};

int main(){
    graph g;
    g.addedge(0,1);
    g.addedge(1,2);
    g.addedge(2,0);
    g.addedge(1,3);
    g.addedge(3,4);
    g.addedge(4,5);
    g.addedge(5,3);

    stack<int> st;
    unordered_map<int,bool> visited;
    for(int i = 0;i<6;i++){
        if(!visited[i]){
            g.topoSort(i,st,visited); // step 1: topological sort
        }
    }

    // step 2: transpose is already created during edge addition
    visited.clear();
    // step 3: do dfs according to topological order on transposed graph
    int count = 0;
    while(!st.empty()){
        int top = st.top();
        st.pop();
        if(!visited[top]){
            count++;
            cout<<"SCC: ";
            g.dfs(top,visited);
            cout<<endl;
        }
    }
    cout<<"Number of strongly connected components: "<<count<<endl;
}