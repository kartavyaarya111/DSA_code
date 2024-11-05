//easy

class Solution {
public:
    string compressedString(string word) {
        string ans;
        int cnt=0;
        for(int i=0;i<word.length();i++){
            if(cnt==0){
                cnt=1;
            }else{
                if(word[i]==word[i-1]){
                    cnt++;
                    if(cnt==9){
                        ans+= to_string(cnt) + word[i];
                        cnt=0;
                    }
                }else{
                    ans+= to_string(cnt) + word[i-1];
                    cnt=1;
                }
            }
        }
        if(cnt)
        ans+= to_string(cnt) + word.back();
        return ans;
    }
};