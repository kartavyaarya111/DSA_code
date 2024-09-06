// no need to revise


class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sum = 0;
        for(auto& x:rolls)  sum+=x;
        int m = rolls.size();
        int tot = (n+m)*mean;
        tot-=sum;
        if(n*6<tot || tot<n) return {};
        vector<int> ans;
        for(int i=0;i<n;i++){
            // cout<<tot<<" "<<i<<"\n";
            int x =min(6,tot-(n-i-1));
            // cout<<x<<" ";
            ans.push_back(x);
            tot-=ans.back();
        }
        return ans;
    }
};