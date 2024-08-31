//Similar to LCS but I just added other string as reverse of given string and then followed LCS

class Solution {
public:
    int longestPalindromeSubseq(string s1) {
        string s2 =s1;
        reverse(s2.begin(),s2.end());
        int n=s1.length();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        for(int i=0;i<n;i++){
            dp[i][0]=0;
            dp[0][i]=0;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        string ans="";
        int i=n,j=n;
        while(i>0 && j>0){
            if(s1[i-1]==s2[j-1]){
                ans = s1[i-1] + ans;
                i--;
                j--;
            }else{
                dp[i-1][j]>dp[i][j-1]?i--:j--;
            }
        }
        cout<<ans;
        return dp[n][n];
    }
};