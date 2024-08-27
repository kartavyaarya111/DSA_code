class Solution {
public:
    int strStr(string txt, string pat) {
            int patL = pat.length(),txtL = txt.length();
            for(int i=0;i<txtL;i++){
                int l=0,r=i;
                while(txt[r]==pat[l] && l<patL && r<txtL){
                    l++;r++;
                }
                if(l==patL) return i;
            }
            return -1;
    }
};

//I have also done this question with other approaches like KMP, check it out in leetcode.