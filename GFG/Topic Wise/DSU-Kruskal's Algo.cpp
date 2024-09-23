//Must revise
//For finding MST using Kruskal's algo, we first need to write code for DSU
//DSU checks whether two nodes belonging to same graph or not in O(1) time
//if two nodes not then connest them for MST anf if they belonhs that means if we connect them them it will form cycle.
//Kruskal algo: first dort edges as per weight, then using DSU connect edges that can be used to form MST

class DisjointSet{
    vector<int> rank,size,parent;
public:
    DisjointSet(int n){
        rank.resize(n+1,1);
        parent.resize(n+1,1);
        for(int i=0;i<=n;i++)   parent[i]=i;
    }
    int findUPar(int node){
        if(node==parent[node])  return node;
        return parent[node]= findUPar(parent[node]);
    }
    void unionByRank(int u,int v){
        int upar = findUPar(u),vpar = findUPar(v);
        if(upar==vpar)  return;
        if(rank[upar]<rank[vpar])   parent[upar]=vpar;
        else if(rank[upar]>rank[vpar])   parent[vpar]=upar;
        else{
            parent[vpar]=upar;
            rank[upar]++;
        }
    }
};
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	static bool comp(vector<int> &a,vector<int> &b){
	    return a[2]<b[2];
	}
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<vector<int>> arr;
        for(int i=0;i<V;i++){
            for(auto &x:adj[i]){
                arr.push_back({i,x[0],x[1]});
            }
        }
        sort(arr.begin(),arr.end(),comp);
        int ans=0;
        DisjointSet obj(V);
        for(auto &x:arr){
            if(obj.findUPar(x[0]) != obj.findUPar(x[1])){
                ans+=x[2];
                obj.unionByRank(x[0],x[1]);
            }
        }
        return ans;
    }
};