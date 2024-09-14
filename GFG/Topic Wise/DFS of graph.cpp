//Easy to do

class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfs(vector<int> adj[],vector<int>& vis,int j, vector<int> &ans){
        ans.push_back(j);
        for(int i=0;i<adj[j].size();i++){
            if(vis[adj[j][i]]==0){
                vis[adj[j][i]]=1;
                dfs(adj,vis,adj[j][i],ans);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> ans, vis(V,0);
        vis[0]=1;
        dfs(adj,vis,0,ans);
        return ans;
    }
};