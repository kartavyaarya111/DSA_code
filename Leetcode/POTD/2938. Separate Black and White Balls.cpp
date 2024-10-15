//1st approach
//TLE
class Solution {
public:
    long long minimumSteps(string s) {
        long long ans=0;
        int n=s.length();
        bool f=1;
        while(f){
            f=0;
            for(int j=0;j<n-1;j++){
                if(s[j]=='1' && s[j+1]=='0'){
                    swap(s[j],s[j+1]);
                    ans++;
                    f=1;
                }
            }
        }
        return ans;
    }
};

//2nd approach
//checked solution
//you have to swap to number of 0s to the right of 1
class Solution {
public:
    long long minimumSteps(string s) {
        long long ans=0;
        int n=s.length();
        vector<int> v(n,0);
        // v.back() = s[n-1]=='0'?1:0;
        for(int i=n-2;i>=0;i--){
            v[i] = v[i+1]+(s[i+1]=='0'?1:0);
            // cout<<v[i]<<" ";
        }
        for(int i=0;i<n-1;i++){
            if(s[i]=='1')
                ans+=v[i];
        }
        return ans;
    }
};



//3rd approach
//at each step count number of 1
//when 0 comes add those 1 in answer
class Solution {
public:
    long long minimumSteps(string s) {
        long long ans=0,bl=0;
        int n=s.length();
        for(auto& x:s){
            if(x=='1')  bl++;
            else    ans+=bl;
        }
        return ans;
    }
};