class Solution {
public:
    string makeFancyString(string s) {
        string ans;
        for(auto& x:s){
            int len = ans.length();
            if(len>=2 && x==ans[len-1] && ans[len-1]==ans[len-2]){
                continue;
            }else{
                ans+=x;
            }
        }
        return ans;
    }
};