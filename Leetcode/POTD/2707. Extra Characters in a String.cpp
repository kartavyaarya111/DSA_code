//3 Approaches
//1. Recursion
//TLE:
//Intuition: for each index check if a word can be formed and present in dictionary
//if skipped then add 1
//choose minimum among chosen word and ignored one
class Solution {
public:
    int solve(string& s, unordered_set<string>& st, int i,int& n){
        if(i>=n)   return 0;
        int ans = 1+solve(s,st,i+1,n);
        for(int j=i;j<n;j++){
            if(st.count(s.substr(i,j-i+1))){
                ans = min(ans,solve(s,st,j+1,n));
            }
        }
        return ans;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string> st;
        int n=s.length();
        for(auto& x:dictionary){
            st.insert(x);
        }
        return solve(s,st,0,n);
    }
};

//Memoization
class Solution {
public:
    vector<int> dp;
    int solve(string& s, unordered_set<string>& st, int i,int& n){
        if(i>=n)   return 0;
        if(dp[i]!=-1)   return dp[i];
        int ans = 1+solve(s,st,i+1,n);
        for(int j=i;j<n;j++){
            if(st.count(s.substr(i,j-i+1))){
                ans = min(ans,solve(s,st,j+1,n));
            }
        }
        return dp[i]=ans;

    }
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string> st;
        int n=s.length();
        dp.resize(n,-1);
        for(auto& x:dictionary){
            st.insert(x);
        }
        return solve(s,st,0,n);
    }
};



//Tabular
class Solution {
public:
    vector<int> dp;
    // int solve(string& s, unordered_set<string>& st, int i,int& n){
    //     if(i>=n)   return 0;
    //     if(dp[i]!=-1)   return dp[i];
    //     int ans = 1+solve(s,st,i+1,n);
    //     for(int j=i;j<n;j++){
    //         if(st.count(s.substr(i,j-i+1))){
    //             ans = min(ans,solve(s,st,j+1,n));
    //         }
    //     }
    //     return dp[i]=ans;

    // }
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string> st;
        int n=s.length();
        dp.resize(n+1,0);
        for(auto &x:dictionary){
            st.insert(x);
        }
        for(int i=n-1;i>=0;i--){
            dp[i]=1+dp[i+1];
            for(int j=i;j<n;j++){
                if(st.count(s.substr(i,j-i+1)))
                    dp[i] = min(dp[i],dp[j+1]);
            }
        }
        return dp[0];
    }
};