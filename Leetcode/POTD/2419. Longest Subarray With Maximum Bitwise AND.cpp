//done with myself
//initially i find max element then started doing operationto find longest length
//best approach is to find max element while iterating and finding max length

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi = nums[0];
        int ans=1,len=1;
        for(int i=1;i<nums.size();i++){
            int x=nums[i];
            if(x>maxi){
                len=1;
                ans=1;
                maxi=x;
            }else if(x==maxi){
                len++;
                ans=max(ans,len);
            }else{
                len=0;
            }
        }
        return ans;
    }
};