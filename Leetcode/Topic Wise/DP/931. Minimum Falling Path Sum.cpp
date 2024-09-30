//directly done tabular

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& t) {
        int m= t.size(),ans=INT_MAX;
        if(m==1)    return *min_element(t[0].begin(),t[0].end()) ;
        vector<vector<int>>dp =t;
        for(int i=1;i<m;i++){
            for(int j=0;j<m;j++){
                int a=INT_MAX,b=INT_MAX,c=INT_MAX;
                if(j-1>=0)    a=t[i][j]+dp[i-1][j-1];
                b= t[i][j]+dp[i-1][j];
                if(j+1<m)    c=t[i][j]+dp[i-1][j+1];
                dp[i][j]=min({a,b,c});
                if(i==m-1)  ans=min(ans,dp[i][j]);
            }
        }
        return ans;
    }
};