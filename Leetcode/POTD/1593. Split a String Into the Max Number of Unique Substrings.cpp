//good question
//revise
//used recursion and thought of going to every position from each place
// in each recursion: take substring up to each place and then call function again

class Solution {
public:
    void solve(string&s,int i, unordered_set<string> &st, int &ans){
        if(i==s.length()){
            ans=max(ans,(int)st.size());
            return;
        }
        for(int j=i;j<s.size();j++){
            string cur = s.substr(i,j-i+1);
            if(st.find(cur)==st.end()){
                st.insert(cur);
                solve(s,j+1,st,ans);
                st.erase(cur);
            }
        }
    }
    int maxUniqueSplit(string s) {
        int ans=0;
        unordered_set<string> st;
        solve(s,0,st,ans);
        return ans;
    }
};