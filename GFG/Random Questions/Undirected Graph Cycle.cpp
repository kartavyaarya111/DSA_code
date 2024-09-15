//Good question must revise
//think of a way to do it with BFS
//approach: step by step go to neighbour of each level, if it already visited it means there is a cycle.

bool isCycle(int V, vector<int> adj[]) {
        vector<int> v(V,0);
        queue<pair<int,int>> q;
        for(int i=0;i<V;i++){
            if(v[i]==1) continue;
            
            q.push({i,-1});
            v[i]=1;
            while(!q.empty()){
                pair<int, int> p = q.front();  // Get the front element
                q.pop();
                
                int i = p.first;  // Current node
                int prev = p.second; 
                for(auto x:adj[i]){
                    if(x==prev)  continue;
                    if(v[x]!=0) return 1;
                    v[x]=1;
                    q.push({x,i});
                }
            }
        }
        return 0;
    }