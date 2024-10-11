//biweekly 140

class Solution {
public:
    long long maximumTotalSum(vector<int>& ht) {
        priority_queue<int> pq;
        for(int i=0;i<ht.size();i++){
            pq.push(ht[i]);
        }
        int maxi = pq.top();
        long long sum = 0;
        while(!pq.empty()){
            if(maxi<=0) return -1;
            int node = pq.top();
            pq.pop();
            maxi=min(node,maxi);
            sum+=maxi;
            maxi--;
        }
        return sum;
    }
};