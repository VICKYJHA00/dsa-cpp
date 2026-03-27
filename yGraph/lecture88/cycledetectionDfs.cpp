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


    bool isCycleDfs(int src){
        stack<int> s;
        unordered_map<int,int> parent;
        unordered_map<int,bool> visited;
        s.push(src);
        parent[src] = -1;
        while(!s.empty()){
            int top = s.top();
            s.pop();
            if(!visited[top]){
                visited[top] = true;
            } 

            for(auto i: adj[top]){
                if(visited[i] && parent[top] != i){
                    return true;
                }
                else if(!visited[i]){
                    s.push(i);
                    parent[i] = top;
                }
            }
        }
        return false;
    }

    // bool isCycleBfs(int src){
    //     queue<int> q;
    //     unordered_map<int,int> parent;
    //     unordered_map<int,bool> visited;
    //     q.push(src);
    //     visited[src] = true;
    //     parent[src] = -1;
    //     while(!q.empty()){
    //         int front = q.front();
    //         q.pop();
    //         for(auto i: adj[front]){
    //             if(visited[i]  && parent[front] != i){
    //                 return true;
    //             }
    //             else if(!visited[i]){
    //                 q.push(i);
    //                 visited[i] = true;
    //                 parent[i] = front;
    //             }
    //         }
    //     }
    //     return false;
    // }

    void print(){
        for(auto i:adj){
            cout<<i.first<<"->";
            for(auto j:i.second){
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }

    // void dfs(int src){
    //     stack<int>s;
    //     unordered_map<int,bool> visited;
    //     s.push(src);
    //     visited[src] = true;
    //     while(!s.empty()){
    //         int top = s.top();
    //         s.pop();
    //         cout<<top<<" ";
    //         for(auto i: adj[top]){
    //             if(!visited[i]){
    //                 visited[i] = true;
    //                 s.push(i);
                    
    //             }
    //         }
    //     }
    // }

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
    // g.dfs(0);
    if(g.isCycleDfs(0)){
        cout<<"Cycle is  present"<<endl;
    }else{
        cout<<"Cycle is not present"<<endl;
    }

    return 0;
}