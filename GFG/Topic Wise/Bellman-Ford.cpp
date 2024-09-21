//Must be directed graph
//we need to relax V-1 times and then put new lesser weight if possible
//and in the end again relax one more time and check if weight is again decreasing then return {-1}


vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        vector<int> ans(V,1e8);
        ans[S]=0;
        for(int i=1;i<V;i++){
            for(auto& x:edges){
                int u = x[0], v= x[1], w=x[2];
                if(ans[u]==1e8)  continue;
                if(ans[u]+w<ans[v]){
                    ans[v]=ans[u]+w;
                }
            }
        }
        for(auto& x:edges){
            int u = x[0], v= x[1], w=x[2];
            if(ans[u]==1e8)  continue;
            if(ans[u]+w<ans[v]){
                return {-1};
            }
        }
        return ans;
    }