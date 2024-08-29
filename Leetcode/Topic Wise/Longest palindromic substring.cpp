// Remember this approach for interview
//expanding around center
class Solution {
public:
    int n;
    string solve(string s, int i ,int j){
        while(i>=0 && j<n && s[i]==s[j]){
            i--;j++;
        }
        return s.substr(i+1,j-i-1);
    }
    string longestPalindrome(string s) {
        n =s.length();
        string ans="";
        for(int i=0;i<n;i++){
            string odd = solve(s,i,i);
            if(i<n-1){
                string even = solve(s,i,i+1);
                if(ans.length()<even.length()){
                    ans=even;
                }
            }
            ans = ans.length()<odd.length()?odd:ans;
        }
        return ans;
    }
};



//Memoization
class Solution {
public:
    vector<vector<int>> dp;
    bool palin(string &s, int i, int j) {
        if (i >= j) return true;
        if (dp[i][j] != -1) return dp[i][j]; // Return precomputed result

        if (s[i] == s[j]) {
            return dp[i][j] = palin(s, i + 1, j - 1); // Check inner substring
        }
        return dp[i][j] = false;
    }

    string longestPalindrome(string s) {
        int len=0,idx=0;
        int n=s.length();
        dp.assign(n,vector<int>(n,-1));
        for (int i = 0; i < n; i++) {
            for(int j=i+len;j<n;j++){
                if(palin(s,i,j)){
                    len = (j-i+1);
                    idx = i;
                }
            }
        }
        return s.substr(idx,len);
    }
};


//One more better approach present but no need to learn

//all other approach present but give TLE