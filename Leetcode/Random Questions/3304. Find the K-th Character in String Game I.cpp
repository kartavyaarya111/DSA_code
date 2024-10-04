class Solution {
public:
    char kthCharacter(int k) {
        string s ="a";
        while(s.length()<k){
            int sz = s.length();
            for(int i=0;i<sz;i++){
                if(s[i]=='z')   s+='a';
                else
                    s += (s[i]+1);
            }
        }
        return s[k-1];
    }
};
