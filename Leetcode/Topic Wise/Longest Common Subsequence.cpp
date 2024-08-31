//Memoization approach
class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i, int j, string& s1, string& s2){
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1)    return dp[i][j];
        if(s1[i]==s2[j])    return dp[i][j]= 1+solve(i-1,j-1,s1,s2);
        else    return dp[i][j]= max(solve(i-1,j,s1,s2),solve(i,j-1,s1,s2));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.length(),n2=text2.length();
        dp.resize(n1,vector<int>(n2,-1));
        return solve(n1-1,n2-1,text1,text2);
    }
};

//Bottom UP Tabular approach
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.length(),n2=text2.length();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,-1));
        for(int i=0;i<=n1;i++)  dp[i][0]=0;
        for(int j=1;j<=n2;j++)   dp[0][j]=0;
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(text1[i-1]==text2[j-1])    dp[i][j]= 1+dp[i-1][j-1];
                else    dp[i][j]= max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n1][n2] ;
    }
};