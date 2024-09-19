//1st Approach: BFS i.e. Kahn's algorithm (Using indegree vector and queue)

vector<int> topoSort(int V, vector<int> adj[]) {
	    vector<int> indeg(V,0);
	    for(int i=0;i<V;i++){
	        for(auto& x:adj[i])  indeg[x]++;
	    }
	    queue<int> q;
	    vector<int> ans,vis(V,0);
	    for(int i=0;i<V;i++)  if(!indeg[i]) {q.push(i); ans.push_back(i);}
	    while(!q.empty()){
	        int top = q.front();
	        q.pop();
	        for(auto& x:adj[top]){
	            if(indeg[x]){
	                indeg[x]--;
	                if(!indeg[x]){   q.push(x); ans.push_back(x);}
	            }
	        }
	    }
	    return ans;
	}



//2nd Approach: DFS (Backtacking and visited array)
public:
    void dfs(int node, vector<int> adj[], vector<int>& ans,vector<int>& vis){
        vis[node]=1;
        for(auto& x:adj[node]){
            if(vis[x]==0)
                dfs(x,adj,ans,vis);
        }
        ans.push_back(node);
    }
	vector<int> topoSort(int V, vector<int> adj[]) {
	    vector<int> ans,vis(V,0);
	    for(int i=0;i<V;i++){
	        if(vis[i]==0)   dfs(i,adj,ans,vis);
	    }
	    reverse(ans.begin(),ans.end());
	    return ans;
	}