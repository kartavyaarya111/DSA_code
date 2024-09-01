//Weekly contest 
// no need of revision

class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        priority_queue<int> pq;
        vector<int> ans;
        for(auto &x:queries){
            int sum = abs(x[0])+ abs(x[1]);
            if(pq.size()<k){
                pq.push(sum);
            }else{
                if(pq.top()>sum){
                    pq.pop();
                    pq.push(sum);
                }
            }
            if(pq.size()<k) ans.push_back(-1);
            else    ans.push_back(pq.top());
        }
        return ans;
    }
};