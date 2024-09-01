//Biweekly contest 31/8/24
//Revise how to covert char into num and vice versa


class Solution {
public:
    string stringHash(string s, int k) {
        string ans;
        int sz= s.length();
        for(int i=0;i<sz;i=i+k){
            long long sum=0;
            string temp =s.substr(i,k);
            // cout<<temp;
            for(auto &x:temp){
                long long z = x-'a';
                sum+= z;
                // cout<<z<<" ";
            }
            sum%=26;
            char c = 'a'+sum;
            ans += c;
            // cout<<" ";
        }
        return ans;
    }
};