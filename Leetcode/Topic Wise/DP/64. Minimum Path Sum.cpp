//directly done tabulation 

class Solution {
public:
    int minPathSum(vector<vector<int>>& v) {
        int m = v.size(),n=v[0].size();
        vector<vector<int>> dp(m,vector<int>(n,INT_MAX));
        dp[0][0]=v[0][0];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0)    continue;
                if(i-1>=0)
                    dp[i][j]=v[i][j]+dp[i-1][j];
                if(j-1>=0)
                    dp[i][j] = min(dp[i][j], v[i][j]+dp[i][j-1]);
            }
        }
        return dp[m-1][n-1];
    }
};