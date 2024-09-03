//Easy question no need to revise

class Solution {
public:
    int getLucky(string s, int k) {
        int ans=0;
        for(auto& x:s){
            int tmp = x-'a'+1;
            while(tmp>0){
                ans= ans + (tmp%10);
                tmp/=10;
            }
        }
        k--;
        while(k--){
            int tmp = ans;
            ans=0;
            while(tmp){
                ans= ans + (tmp%10);
                tmp/=10;
            }
        }
        return (int)ans;
    }
};