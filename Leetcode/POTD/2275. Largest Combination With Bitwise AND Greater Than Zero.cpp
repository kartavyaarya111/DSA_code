//it given me TLE in just 9th test case out of 80

class Solution {
public:
    int n,ans=0;
    vector<int> dp;
    void solve(vector<int>&arr ,int i, int temp, int cnt){
        if(i==n){
            if(temp>0 && cnt>ans){
                ans=cnt;
            }
            // cout<<temp<<" "<<cnt<<" "<<ans<< endl;
            return;
        }
        solve(arr,i+1,temp,cnt);
        if(temp>0)
        solve(arr,i+1,temp&arr[i],cnt+1);
    }
    int largestCombination(vector<int>& candidates) {
        n=candidates.size();
        // dp.resize(n,vector<int>(n,-1));
        for(int i=0;i<n;i++)
        solve(candidates,i+1,candidates[i],1);
        return ans;
    }
};



//then saw youtube intuition 
//got to know count number of elements in array at each position having 1
//it will tell number of elements in array whose AND operator will be greater than 1.
class Solution {
public:
    int largestCombination(vector<int>& arr) {
        int n=arr.size(),ans=0;
        for(int bit=0;bit<32;bit++){
            int cnt=0;
            for(int &x:arr){
                if(x&(1<<bit))  cnt++;
            }
            ans=max(ans,cnt);
        }
        return ans;
    }
};


//for better performance 
//Contraint was arr[i]<=1e7; so I calculated number of n=bits required for 1e7 
//using formula log2(1e7)+1 that is 24

class Solution {
public:
    int largestCombination(vector<int>& arr) {
        int n=arr.size(),ans=0;
        //log(1e7)+1=24
        for(int bit=0;bit<24;bit++){
            int cnt=0;
            for(int &x:arr){
                if(x&(1<<bit))  cnt++;
            }
            ans=max(ans,cnt);
        }
        return ans;
    }
};