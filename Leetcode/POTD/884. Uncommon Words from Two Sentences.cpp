//easy question no need to revise

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> ans;
        unordered_map<string,int> m1;
        string temp="";
        for(int i=0;i<s1.size();i++){
            if(s1[i]==' '){
                m1[temp]++ ;
                temp="";
            }else{
                temp+=s1[i];
            }
        }
        m1[temp]++;

        temp="";
        for(int i=0;i<s2.size();i++){
            if(s2[i]==' '){
                m1[temp]++ ;
                temp="";
            }else{
                temp+=s2[i];
            }
        }
        m1[temp]++;

        for(auto &x:m1){
            if(x.second==1)
                ans.push_back(x.first);
        }
        return ans;
    }
};