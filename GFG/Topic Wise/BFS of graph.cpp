vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        queue<int> q;
        q.push(0);
        vector<int> ans,v(V,0);
        v[0]=1;
        while(!q.empty()){
            int z = q.front();
            q.pop();
            ans.push_back(z);
            for(auto &x:adj[z]){
                if(!v[x]){    q.push(x);    v[x]=1;}
            }
        }
        return ans;
    }