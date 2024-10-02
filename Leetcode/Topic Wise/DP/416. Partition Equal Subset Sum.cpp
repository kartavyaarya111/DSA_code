//similar to subset sum problem
//Approach: dividing array in two parts means sum of half part equals to other half
//make target =sum/2; and do like subset sum problem

//Memoization
class Solution {
public:
    vector<vector<int>> dp;
    bool solve(vector<int>& nums, int i, int sum){
        if(sum==0)  return true;
        if(i==0)    return nums[i]==sum;
        if(dp[i][sum]!=-1)  return dp[i][sum];
        bool nottake = solve(nums,i-1,sum);
        bool take=0;
        if(sum>nums[i])
            take= solve(nums,i-1,sum-nums[i]);
        return dp[i][sum]= take || nottake;
    }
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum%2)   return false;
        dp.assign(nums.size(),vector<int>(sum/2+1,-1));
        return solve(nums,nums.size()-1,sum/2);
    }
};


//tabulation
//only important point is think like top to down
//in bottom up we were getting if i==0 and sum==target then return true so here we will put dp[0][arr[0]]=true;
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum%2)   return false;
        int n=nums.size();
        if(n==1)    return false;
        sum/=2;
        vector<vector<bool>> dp(n,vector<bool>(sum*2+1,0));
        for(int i=0;i<n;i++)    dp[i][0]=true;
        dp[0][nums[0]] =true;
        for(int i=1;i<n;i++){
            for(int j=1;j<=sum;j++){
                bool nottake=dp[i-1][j];
                bool take=false;
                if(j>=nums[i])   take=dp[i-1][j-nums[i]];
                dp[i][j]=take||nottake;
            }
        }
        return dp[n-1][sum];
    }
};