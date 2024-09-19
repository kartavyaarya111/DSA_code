//good backtracking question
//revise

class Solution {
public:
    vector<int> diffWaysToCompute(string exp) {
        vector<int> ans;
        for(int i=0;i<exp.length();i++){
            if(exp[i]=='+' || exp[i]=='-' || exp[i]=='*'){
                string l = exp.substr(0,i),r=exp.substr(i+1);
                vector<int> left = diffWaysToCompute(l);
                vector<int> right = diffWaysToCompute(r);
                for(auto &x:left){
                    for(auto& y:right){
                        if(exp[i]=='+')    ans.push_back(x+y);
                        else if(exp[i]=='-')    ans.push_back(x-y);
                        else    ans.push_back(x*y);
                    }
                }
            }
        }
        if(!ans.size()) ans.push_back(stoi(exp));
        return ans;
    }
};