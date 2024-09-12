//no need to revise

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int ans=0;
        int m[26]={0};
        for(auto& x:allowed)
            m[x-'a']=1;
        for(auto &x:words){
            bool is=1;
            for(auto& u:x){
                if(m[u-'a']==0){
                    is=0;
                    break;
                }
            }
            if(is)  ans++;
        }
        return ans;
    }
};