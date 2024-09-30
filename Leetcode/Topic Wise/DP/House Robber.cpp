//Memoization (Top Down)
class Solution {
public:
    int n;
    vector<int> dp;
    int solve(vector<int>& nums, int i){
        if(i<0) return 0;
        if(dp[i]!=-1) return dp[i];
        int ans = solve(nums,i-1);
            ans=max(ans, nums[i]+solve(nums,i-2));
        return dp[i]= ans;
    }
    int rob(vector<int>& nums) {
        n=nums.size();
        if(n==1)    return nums[0];
        dp.assign(n,-1);
        return solve(nums,n-1);
    }
};


//Bottom UP
class Solution {
public:
    int n;
    int rob(vector<int>& nums) {
        n=nums.size();
        if(n==1)    return nums[0];
        int prvs1=nums[0];
        int prvs2=0;
        for(int i=1;i<n;i++){
            int ans=max(prvs1,nums[i]+prvs2);
            prvs2=prvs1;
            prvs1=ans; 
        }
        return prvs1;
    }
};