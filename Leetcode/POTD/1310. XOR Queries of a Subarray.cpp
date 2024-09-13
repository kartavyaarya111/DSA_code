//two approaches
//1. using basic for loop and for each given range find out xor
//2. Use the concept of xor property
//   first store xor in continuous manner in a vector
//   then take xor of end of range and a place before start of range 

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> ans,v ;
        v.push_back(arr[0]);
        for(int i=1;i<arr.size();i++){
            v.push_back(arr[i]^v.back());
        }
        for(auto &x:queries){
            if(x[0]){
                ans.push_back(v[x[1]]^v[x[0]-1]);
            }else{
                ans.push_back(v[x[1]]);
            }
        }
        return ans;
    }
};