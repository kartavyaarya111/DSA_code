//Used for building MST
// It's approach is to find the minimun weight neighbour of the vertices that are present in already taken MST
//sum up the weight of vertices that u r going to take part in MST
int spanningTree(int V, vector<vector<int>> adj[]){
    int ans=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> vis(V,0);
    pq.push({0,0});
    while(!pq.empty()){
        int wt=pq.top().first;
        int node = pq.top().second;
        pq.pop();
        if(vis[node])   continue;
        vis[node]=1;
        ans+=wt;
        for(auto &x:adj[node]){
            if(vis[x[0]])   continue;
            pq.push({x[1],x[0]});
        }
    }
    return ans;
}