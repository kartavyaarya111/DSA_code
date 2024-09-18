//good question
//revise the concept of comparator

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> v;
        for(auto &x: nums){
            v.push_back(to_string(x));
        }
        sort(v.begin(),v.end(), [](const string &a,const string& b){
            return a+b > b+a;
        });
        if(v[0]=="0")    return "0";
        string ans;
        for(auto& x:v)  ans+=x;
        return ans;
    }
};