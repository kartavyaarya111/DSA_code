//memoization

class Solution {
public:
    vector<vector<int>> dp;
    bool check(int i, int j, int& m, int& n){
        if(i<0 || j<0 || i>=m || j>=n)  return false;
        return true;
    }
    int solve(int i, int j, int& m, int& n){
        if(i==0 && j==0)    return 1;
        if(dp[i][j]!=-1)    return dp[i][j];
        int ans = 0;
        if(check(i-1,j,m,n))    ans+=solve(i-1,j,m,n);
        if(check(i,j-1,m,n))    ans+=solve(i,j-1,m,n);
        return dp[i][j]=ans;
    }
    int uniquePaths(int m, int n) {
        dp.assign(m,vector<int>(n,-1));
        return solve(m-1,n-1,m,n);
    }
};


//Tabular (top- down)
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        dp[1][1]=1;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(i==1 && j==1)    continue;
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m][n];
    }
};