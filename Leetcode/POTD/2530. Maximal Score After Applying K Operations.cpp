//Easy

class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long ans=0;
        priority_queue<int> pq;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        while(k--){
            int top = pq.top();
            ans+=top;
            pq.pop();
            pq.push((int)(ceil(top/3.0)));
        }
        return ans;
    }
};