//One of rthe most toughest question about graph
//Revise it as I had not done it by myself even not the code


class Solution {
public:
    using ll = long long;
    typedef pair<long,long> P;
    ll solve(vector<vector<int>>& edges, int n, int source, int destination){
        unordered_map<ll,vector<pair<int,int>>> adj;
        for(auto& x:edges){
            if(x[2]!=-1){
                adj[x[0]].push_back({x[1],x[2]});
                adj[x[1]].push_back({x[0],x[2]});
            }
        }
        priority_queue<P,vector<P>,greater<P>> pq;
        vector<ll> result(n,INT_MAX);
        vector<bool> visited(n,false);
        result[source]=0;
        pq.push({0,source});
        while(!pq.empty()){
            auto [dis,node] = pq.top();
            pq.pop();
            if(visited[node])   continue;
            visited[node]=true;

            for(auto& [nbr,wt]: adj[node]){
                if(result[nbr]>dis+wt){
                    result[nbr]=dis+wt;
                    pq.push({result[nbr],nbr});
                }
            }
        }
        return result[destination];
    }
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        ll curr = solve(edges, n, source, destination);
        if(curr<target){
            return {};
        }
        bool match = (curr == target);
        if(match){
            for(auto &x:edges){
                if(x[2]== -1){
                    x[2]=1e9;
                }
            }
            return edges;
        }
        for(auto& x:edges){
            if(x[2]==-1){
                x[2]= (match==true)?1e9:1;
                if(match!=true){
                    ll newdis = solve(edges,n,source,destination);
                    if(newdis<=target){
                        match=true;
                        x[2] += (target - newdis);
                    }
                }
            }
        }
        if(match ==false){
            return {};
        }
        return edges;
    }
};