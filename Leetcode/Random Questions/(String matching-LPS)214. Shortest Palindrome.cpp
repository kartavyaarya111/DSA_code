//Must revise
//you will get a question where string matching LPS concept is used

//My first approach
//It gave TLE
class Solution {
public:
    string shortestPalindrome(string s) {
        int i=0,j=s.length()-1;
        int x=j;
        string ans;
        while(i<j){
            if(s[i]!=s[j]){
                ans+=s[x];
                x--;
                i=0;j=x;
            }else{
                i++;j--;
            }
        }
        return ans+s;
    }
};


//Now I have learnt from youtube and got to know about memcmp(string 1 pointer, string 2 pointer, length to be compared)
// this function will give output 0 if string matches else 1.
class Solution {
public:
    string shortestPalindrome(string s) {
        int n=s.length();
        string rv = s;
        reverse(rv.begin(),rv.end());
        for(int i=0;i<n;i++){
            if( memcmp(s.c_str(),rv.c_str()+i,s.length()-i)==0 ){
                return rv.substr(0,i)+s;
            }
        }
        return rv+s;
    }
};


//Approach 3: Used KMP LPS concept 
//main thought is make a new string and compare how many length is same as start
class Solution {
public: 
    vector<int> solve(string &temp){
        int n=temp.length();
        vector<int> LPS(n,0);
        int len=0;
        for(int i=1;i<n;i++){
            if(temp[len]==temp[i]){
                LPS[i]=(++len);
            }else if(len==0){
                LPS[i]=0;
            }else{
                len = LPS[--len];
                i--;
            }
        }
        return LPS;
    }
    string shortestPalindrome(string s) {
        string rev = s;
        reverse(rev.begin(),rev.end());
        string temp = s+"@"+rev;
        vector<int> LPS = solve(temp);
        int len = LPS.back();
        temp = rev.substr(0,s.length()-len);
        return temp+s;
    }
};