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