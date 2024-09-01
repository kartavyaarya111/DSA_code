//Must revise [hard problem]
//Concept of dp with bit masking
//Didn't understand clearly
//https://www.youtube.com/watch?v=wm97S7dSNrU  Time stamp: 10:22:00


class Solution {
public:
    vector<int> val[101];
    int dp[101][(1<<10)];
    int solve(int i, int mask){
        if(i==101)  return 0;
        if(dp[i][mask]==-1){
            int ans = solve(i+1,mask);
            for(auto j:val[i]){
                if((mask & (1<<j)) == 0){
                    ans = max(ans, i+solve(i+1,mask | (1<<j)));
                }
            }
            dp[i][mask]=ans;
        }
        return dp[i][mask];
    }
    int maxScore(vector<vector<int>>& grid) {
        for(int i=0;i<=100;i++){
            val[i].clear();
            for(int j=0;j<(1<<10);j++)
                dp[i][j]=-1;
        }
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                    val[grid[i][j]].push_back(i);
                }
            }
        return solve(1,0);
    }
};