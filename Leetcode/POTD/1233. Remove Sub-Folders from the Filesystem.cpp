//done by me
//no need to revise

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(),folder.end());
        unordered_set<string> st;
        vector<string> ans;
        for(auto&x:folder){
            int i=x.length()-1;
            while(i>=0){
                if(st.find(x.substr(0,i+1))!=st.end())  break;
                while(i>=0 && x[i]!='/')    i--;
                i--;
                if(i==-1){
                    ans.push_back(x);
                    st.insert(x);
                }
            }
        }
        return ans;
    }
};