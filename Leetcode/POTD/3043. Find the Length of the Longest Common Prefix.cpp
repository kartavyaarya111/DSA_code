//good question
//revise cocept


class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        vector<string>a,b;
        for(auto& x:arr1){
            a.push_back(to_string(x));
        }
        for(auto& x:arr2){
            b.push_back(to_string(x));
        }
        unordered_set<string> s;
        int ans=0;
        for(auto&x:a){
            for(int i=0;i<x.length();i++){
                if(s.find(x.substr(0,i+1))==s.end()){
                    s.insert(x.substr(0,i+1));
                }
            }
        }
        for(auto&x:b){
            for(int i=0;i<x.length();i++){
                if(s.find(x.substr(0,i+1))!=s.end()){
                    ans=max(ans,i+1);
                }else{
                    break;
                }
            }
        }
        return ans;
    }
};