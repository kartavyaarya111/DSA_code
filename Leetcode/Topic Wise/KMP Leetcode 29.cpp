//KMP string matching algorithm
//Complexity: O(m+n) 

class Solution {
public:
    int strStr(string txt, string pat) {
        int txtL = txt.length(), patL = pat.length();
        vector<int> lps(patL);
        int len=0,i=1;
        while(i<patL){
            if(pat[i]==pat[len]){
                len++;
                lps[i]=len;
                i++;
            }else{
                if(len==0){
                    i++;
                }else{
                    len=lps[len-1]; //REMEMBER this Line: here I made mistake i took len=len-1;
                }
            }
        }
        for(auto &x:lps)    cout<<x<<" ";
        i=0;
        int j=0;
        while(i<txtL){
            // cout<<i<<" "<<j<<endl;
            if(txt[i]==pat[j]){
                i++;
                j++;
            }else{
                if(j==0)i++;
                else{
                    j=lps[j-1];
                }
            }
            if(j==patL){
                return i-patL;
            }
        }
        return -1;
    }
};