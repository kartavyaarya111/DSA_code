//Bipartite: adjacent nodes of different colour

//Approach 1: BFS (used queue)
//Revise
class Solution {
public:
    bool check(vector<vector<int>>& graph, int st,vector<int>& v){
        v[st]=0;
        queue<int> q;
        q.push(st);
        while(!q.empty()){
            int i= q.front(); q.pop();
            for(auto& x:graph[i]){
                if(v[x]==-1){
                    v[x]= v[i]==0?1:0;
                    q.push(x);
                }else if(v[x]==v[i]){
                    return 0;
                }
            }
        } 
        return 1;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> v(n,-1);
        for(int i=0;i<n;i++){
            if(v[i]==-1){
                if(!check(graph,i,v)) return 0;
            }
        }
        return 1;
    }
};

//Earlier I was doing same without using queue but here I got to know I'm wrong: graph =[[1],[0,3],[3],[1,2]]
// bool isBipartite(vector<vector<int>>& graph) {
//     int n=graph.size();
//     vector<int> v(n,-1);
//     for(int i=0;i<n;i++){
        // if(v[i]==-1)    v[i]=0;
        // for(auto& x:graph[i]){
        //     if(v[x]==-1){
        //         v[x]= v[i]==0?1:0;
        //     }else if(v[x]==v[i]){
        //         return 0;
        //     }
        // }
//     }
//     return 1;
// }



//Approach 2: DFS
//Did myself
class Solution {
public:
    bool check(vector<vector<int>>& graph, int curr,vector<int>& v){
        bool ans=1;
        for(auto& x:graph[curr]){
            if(v[x]==-1){
                v[x]= v[curr]==0?1:0;
                ans= ans && check(graph,x,v);
            }else if(v[x]==v[curr])   ans=0;
        }
        return ans;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> v(n,-1);
        for(int i=0;i<n;i++){
            if(v[i]==-1){
                v[i]=0;
                if(!check(graph,i,v)) return 0;
            }
        }
        return 1;
    }
};