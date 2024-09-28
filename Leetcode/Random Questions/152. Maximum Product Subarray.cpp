//it is a second approach after brute force
//we have to check if value is zero then put front/rear=1;
//save max value
//intuition is from start multiply each number and same from back and save max value

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans=INT_MIN,n=nums.size();
        int front=1,back=1;
        for(int i=0;i<n;i++){
            front*=nums[i];
            back*=nums[n-i-1];
            ans=max({ans,front,back});
            if(front==0)    front=1;
            if(back==0)    back=1;  
        }
        return ans;
    }
};