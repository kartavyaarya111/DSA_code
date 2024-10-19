//first approach
//easy
class Solution {
public:
    char findKthBit(int n, int k) {
        string s="0";
        for(int i=2;i<=n;i++){
            string z=s;
            s+="1";
            for(int j=z.size()-1;j>=0;j--){
                s+= z[j]=='0'?'1':'0';
            }
            // cout<<s<<" ";
        }
        return s[k-1];
    }
};


//second approach
//use your brain

//done recursion: tried to get only one character that can give answer
//base case when n=1 then we get "0"
//if k> pow(2,n-1) then we need reversed part of previous string 
//else if k==pow then return "1"
//else we move to previous string for same value of k


class Solution {
public:
    char solve(int n,int k){
        if(n==1)    return '0';
        int sz= pow(2,n-1);
        if(sz==k)   return '1';
        if(sz<k)    return solve(n-1,2*sz-k)=='0'?'1':'0';
        return solve(n-1,k);
    }
    char findKthBit(int n, int k) {
        return solve(n,k);
    }
};