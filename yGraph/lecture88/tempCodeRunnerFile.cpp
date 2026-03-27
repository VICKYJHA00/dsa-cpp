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