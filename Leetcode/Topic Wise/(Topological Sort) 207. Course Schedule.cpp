//Topological Sort
//Think of approach lil bit
//Kahn's algorithm

class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int> v[n], ind(n,0);
        for(auto& x:pre){
            v[x[0]].push_back(x[1]);
            ind[x[1]]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(!ind[i])  q.push(i);
        }
        while(!q.empty()){
            int tp = q.front();
            q.pop();
            for(auto &x:v[tp]){
                ind[x]--;
                if(!ind[x]) q.push(x);
            }
        }
        for(auto &x:ind){
            cout<<x<<" ";
            if(x)   return 0;
        }
        return 1;
    }
};

//Made it as DAG and then used a set to store whether node traversed or not
class Solution {
public:
    void dfs(int node, vector<vector<int>>& v, vector<int> &vis,unordered_set<int> &s,int& f){
        vis[node]=1;
        s.insert(node);
        for(auto& x:v[node]){
            if(s.find(x)!=s.end()){
                f=1;return;
            }else if(!vis[x]) dfs(x,v,vis,s,f);
        }
        s.erase(node);
    }
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<vector<int>> v(n);
        for(auto&x:pre){
            v[x[1]].push_back(x[0]);
        }
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            unordered_set<int> s;
            int f=0;
            dfs(i,v,vis,s,f);
            if(f)  return false;
        }
        return 1;
    }
};



//Made it as DAG and then used a indegree vector and then use queue
class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<vector<int>> v(n);
        vector<int> ind(n,0);
        for(auto&x:pre){
            v[x[1]].push_back(x[0]);
            ind[x[0]]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(ind[i]==0)   q.push(i);
        }
        while(!q.empty()){
            int top = q.front();
            q.pop();
            for(auto& x:v[top]){
                ind[x]--;
                if(!ind[x]) q.push(x);
            }
        }
        for(auto &x:ind)    if(x)   return false;    
        return 1;
    }
};