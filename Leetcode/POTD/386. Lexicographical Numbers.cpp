class Solution {
public:
    void solve(int n,int curr, vector<int> &ans){
        if(curr>n)  return;
        ans.push_back(curr);
        for(int i=0;i<=9;i++){
            int newn = curr*10+i;
            solve(n,newn,ans);
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        for(int i=1;i<=9;i++){
            solve(n,i,ans);
        }
        return ans;
    }
};