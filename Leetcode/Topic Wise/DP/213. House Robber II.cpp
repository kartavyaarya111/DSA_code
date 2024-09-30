//revise house robber 1 then do this

//Memoization
class Solution {
public:
    vector<int> dp;
    int n;
    int solve(vector<int>& nums, int end, int start){
        dp[start]=nums[start];
        for(int i=start+1;i<=end;i++){
            int take=nums[i];
            if(i>start+1) take+=dp[i-2];
            int nottake = dp[i-1];
            dp[i]=max(take,nottake);
        }
        return dp[end];
    }
    int rob(vector<int>& nums) {
        n=nums.size();
        if(n==1)    return nums[0];
        dp.assign(n,-1);
        int first = solve(nums,n-1,1);
        dp.assign(n,-1);
        int second = solve(nums,n-2,0);
        return max(first,second);
    }
};

//Tabular
class Solution {
public:
    int n;
    int solve(vector<int>& nums, int end, int start){
        int prvs1=nums[start];
        int prvs2=0;
        for(int i=start+1;i<=end;i++){
            int take=nums[i]+prvs2;
            int nottake = prvs1;
            int ans=max(take,nottake);
            prvs2=prvs1;
            prvs1=ans;
        }
        return prvs1;
    }
    int rob(vector<int>& nums) {
        n=nums.size();
        if(n==1)    return nums[0];
        int first = solve(nums,n-1,1);
        int second = solve(nums,n-2,0);
        return max(first,second);
    }
};