//brute force
class Solution {
public:
    int m,n;
    int solve(vector<vector<int>>& matrix,int i, int j){
            if(i>=m || j>=n)    return 0;
        if(matrix[i][j]==0) return 0;
        int right = solve(matrix,i,j+1);
        int down = solve(matrix,i+1,j);
        int diag = solve(matrix,i+1,j+1);
        return 1+min({right,down,diag});
    }
    int countSquares(vector<vector<int>>& matrix) {
        int ans=0;
        m=matrix.size(),n=matrix[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==1){
                    ans+=solve(matrix,i,j);
                }
            }
        }
        return ans;
    }
};


//memoization
class Solution {
public:
    int m,n;
    vector<vector<int>> dp;
    int solve(vector<vector<int>>& matrix,int i, int j){
        if(i>=m || j>=n)    return 0;
        if(dp[i][j]!=-1)    return dp[i][j];
        if(matrix[i][j]==0) return 0;
        int right = solve(matrix,i,j+1);
        int down = solve(matrix,i+1,j);
        int diag = solve(matrix,i+1,j+1);
        return  dp[i][j]= 1+min({right,down,diag});
    }
    int countSquares(vector<vector<int>>& matrix) {
        int ans=0;
        m=matrix.size(),n=matrix[0].size();
        dp.resize(m,vector<int>(n,-1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==1){
                    ans+=solve(matrix,i,j);
                }
            }
        }
        return ans;
    }
};


//top-down/Tabular
class Solution {
public:
    int m,n;
    vector<vector<int>> dp;
    // int solve(vector<vector<int>>& matrix,int i, int j){
    //     if(i>=m || j>=n)    return 0;
    //     if(dp[i][j]!=-1)    return dp[i][j];
    //     if(matrix[i][j]==0) return 0;
    //     int right = solve(matrix,i,j+1);
    //     int down = solve(matrix,i+1,j);
    //     int diag = solve(matrix,i+1,j+1);
    //     return  dp[i][j]= 1+min({right,down,diag});
    // }
    int countSquares(vector<vector<int>>& matrix) {
        int ans=0;
        m=matrix.size(),n=matrix[0].size();
        dp.resize(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(matrix[i-1][j-1]==1){
                    int top=0,left=0,diag=0;
                    dp[i][j]=1+min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]});
                    ans+=dp[i][j];
                }
            }
        }
        return ans;
    }
};