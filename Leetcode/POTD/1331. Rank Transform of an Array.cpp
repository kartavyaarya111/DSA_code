//easy

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n=arr.size();
        if(n==0)    return arr;
        unordered_map<int,int> m;
        vector<int> v=arr;
        sort(v.begin(),v.end());
        int curr=1;
        for(int i=1;i<n;i++){
            if(v[i-1]!=v[i]){
                m[v[i-1]]=curr++;
            }
        }
        m[v.back()]=curr;
        for(auto &x:arr){
            x=m[x];
        }
        return arr;
    }
};