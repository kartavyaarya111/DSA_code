//first done with bubble approach
//then tried to do in one loop which took nlog(n) time complexity

class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int x=0;
        for(int i=1;i<nums.size();i++){
            if(__builtin_popcount(nums[i])!=__builtin_popcount(nums[x])){
                sort(nums.begin()+x,nums.begin()+i);
                x=i;
            }
        }
        sort(nums.begin()+x,nums.end());
        // cout<<nums[0]<<" ";
        for(int i=1;i<nums.size();i++){
            // cout<<nums[i]<<" ";
            if(nums[i]<nums[i-1])   return false;
        }
        return true;
    }
};