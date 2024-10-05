class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int l1 = s1.length(), l2=s2.length();
        if(l1>l2)   return 0;
        vector<int> m1(26,0) ,m2(26,0);
        for(auto& x:s1) m1[x-'a']++;
        int i=0,j=0;
        while(j<l2){
            m2[s2[j]-'a']++;
            if((j-i+1)==l1){
                if(m1==m2)  return true;
                m2[s2[i++]-'a']--;
            }
            j++;
        }
        return false;
    }
};
