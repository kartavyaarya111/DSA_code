//Graph question important to revise
//watched video for solving

class Solution {
public:
    int n;
    void solve(vector<vector<int>>& stones, int i, vector<int> &v){
        v[i]=1;
        int c = stones[i][0], r =stones[i][1];
        for(int x=0;x<n;x++){
            if( !v[x] && (stones[x][0]==c || stones[x][1]==r) ){
                solve(stones,x,v);
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int ans= 0;
        n = stones.size();
        vector<int> visited(n,0);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                solve(stones,i,visited);
                ans++;
            }
        }
        return n-ans;
    }
};