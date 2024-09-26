//revise
//3 steps to solve:
//1. find topological sort in stack
//2. made new inverted graph
//3. now traverse new graph as per stach elements from top ... everytime a complete dfs done add 1 in ans.

void dfs(stack<int> &topo, vector<vector<int>>& adj, vector<int> &vis, int node){
        vis[node]=1;
        for(auto& x:adj[node]){
            if(vis[x]==0){
                dfs(topo,adj,vis,x);
            }
        }
        topo.push(node);
    }
    void solve(vector<int> &vis,vector<vector<int>>& graph, int node){
        vis[node]=1;
        for(auto& x:graph[node]){
            if(!vis[x]) solve(vis,graph,x);
        }
    }
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        stack<int> topo;
        vector<int> vis(V,0);
        for(int i=0;i<V;i++){
            if(vis[i]==0)
                dfs(topo,adj,vis,i);
        }
        
        vector<vector<int>> graph(V);
        for(int i=0;i<V;i++){
            vis[i]=0;
            for(auto &y:adj[i]){
                graph[y].push_back(i);
            }
        }
        
        int ans = 0;
        while(!topo.empty()){
            int top = topo.top();
            topo.pop();
            if(!vis[top]){
                ans++;
                solve(vis,graph,top);
            }
        }
        return ans;
    }