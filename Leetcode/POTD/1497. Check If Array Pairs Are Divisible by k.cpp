//revise
//if a is present then k-a must be present
//if x is -ve number then convert x to +ve number such that it lies between 1 and k using x=((x%k)+k)%k

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int i=0,j=arr.size()-1;
        unordered_map<int,int> m;
        for(auto &x:arr){
            if(x<0)
                m[(x%k+k)%k]++;
            else
                m[x%k]++;
            // cout<<x%k<<" ";
        }
        if(m[0]%2!=0)   return 0;
        m.erase(0);
        for(auto &x:m){
            // cout<<x.first<<" "<<x.second<<endl;
            if(x.second==0) continue;
            if(m[k-x.first]>0){
                int mini =min(x.second,m[k-x.first]);
                m[x.first]-=mini;
                m[k-x.first]-=mini;
            }
        }
        for(auto&x:m){
            if(x.second>0)  return 0;
        }
        return 1;
    }
};