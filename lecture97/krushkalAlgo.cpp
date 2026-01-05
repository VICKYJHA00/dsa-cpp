#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

bool cmp(vector<int> &a, vector<int> &b){
    return a[2]<b[2];
}

void makeset(int v, vector<int> &parent, vector<int> &rank){
    for(int i=0;i<v;i++){
        parent[i] = i;
        rank[i] = 0;
    }
}

int findparent(int node , vector<int> &parent){
    if(parent[node] == node){
        return node;
    }

    return parent[node] = findparent(parent[node],parent);
}

void unionset(int u, int v, vector<int> &parent,vector<int> &rank){
    u = findparent(u,parent);
    v = findparent(v,parent);

    if(rank[u]<rank[v]){
        parent[u] = v;
    }
    else if(rank[v] <rank[u]){
        parent[v] = u;
    }else{
        parent[v] = u;
        rank[u]++;
    }
}

int krushkal(vector<vector<int>> &edges, int n){
    sort(edges.begin(),edges.end(),cmp);
    vector<int> parent(n), rank(n);
    makeset(n,parent,rank);
    int mincost = 0;
    for(int i = 0;i<edges.size();i++){
        int u = findparent(edges[i][0] , parent);
        int v = findparent(edges[i][1] ,parent );
        int w = edges[i][2];

        if(u != v){
            mincost += w;
            unionset(u,v,parent,rank);
        }
    }

    return mincost;

}

int main(){
    int v = 4; // number of vertices
    vector<vector<int>> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    cout << "Minimum Cost Spanning Tree: " << krushkal(edges, v) << endl;

}