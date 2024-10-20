//good question

//max or value always comes from taking maximum numbers because it never decreases value

class Solution {
public:
    void solve(vector<int>& nums, int i,int curr, int &ans,int maxi){
        if(i==nums.size()){  
            if(curr==maxi)  ans++;
            return;
        }
        solve(nums,i+1,curr,ans,maxi);
        solve(nums,i+1,curr|nums[i],ans,maxi);  
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int maxi=0,count=0;
        for(auto &x:nums)   maxi|=x;
        solve(nums,0,0,count,maxi);
        return count;
    }
};