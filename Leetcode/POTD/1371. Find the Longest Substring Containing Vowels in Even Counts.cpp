//three approaches, done with help of youtube
//1: made a string curr="00000" and a map to store curr and it's first occuring index
//2: made a string curr="00000" and a map to store curr and it's first occuring index converting into string using xor
//3: made a int curr=0 and a map to store curr and it's first occuring index using xor operation and left shift

class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<int,int> m;
        m[0]=-1;
        int curr=0;
        int ans = 0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='a'){
                curr^=(1<<4);
            }else if(s[i]=='e'){
                curr^=(1<<3);
            }else if(s[i]=='i'){
                curr^=(1<<2);
            }else if(s[i]=='o'){
                curr^=(1<<1);
            }else if(s[i]=='u'){
                curr^=(1);
            }
            if(m.find(curr)!=m.end()){
                ans = max(ans,i-m[curr]);
            }else
                m[curr]=i;
        }
        return ans;
    }
};