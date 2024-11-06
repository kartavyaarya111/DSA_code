//easy

class Solution {
public:
    vector<vector<int>> dp;
    int m,n;
    int solve(vector<vector<int>>& grid,int i, int j){
        if(j==n) return 0;
        int ans=0;
        if(dp[i][j]!=-1)    return dp[i][j];
        for(int x=-1;x<2;x++){
            if(i+x>=0 && i+x<m && j+1<n && grid[i+x][j+1]>grid[i][j]){
                ans=max(ans,1+solve(grid,i+x,j+1));
            }
        }
        return dp[i][j]=ans;
    }
    int maxMoves(vector<vector<int>>& grid) {
        m=grid.size(),n=grid[0].size();
        int ans=0;
        for(int i=0;i<m;i++){
            dp.resize(m,vector<int>(n,-1));
            ans = max(ans,solve(grid,i,0));
        }
        return ans;
    }
};