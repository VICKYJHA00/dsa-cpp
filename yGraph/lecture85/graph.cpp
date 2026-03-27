#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

class Graph{
    public:
    unordered_map<int,list<int>> adj;

    void addEdge(int u,int v,bool direction){
        //direction = 0-> undirected
        // direction = 1-> directed
        adj[u].push_back(v);
        if(direction == 0){
            adj[v].push_back(u);
        }
    }

    void printAdj(){
        for(auto i:adj){
            cout<<i.first<<"->";
            for(auto j:i.second){
                cout<<j<<",";
            }
            cout<<endl;
        }
    }
};

int main(){
    int n;
    int m;
    cout<<"Enter number of nodes and Edges"<<endl;
    cin>>n>>m;

    Graph g;

    for(int i=0;i<m;i++){
        int u,v;
        cout<<"Enter u and v"<<endl;
        cin>>u>>v;
        g.addEdge(u,v,0);
    }
    cout<<endl;

    g.printAdj();
    return 0;
}