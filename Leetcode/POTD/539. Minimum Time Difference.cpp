//Did myself

class Solution {
public:
    int findMinDifference(vector<string>& tm) {
        sort(tm.begin(),tm.end());
        int prvMin = stoi(tm[0].substr(3,2));
        int prvHr = stoi(tm[0].substr(0,2)) * 60;
        int prvTime = prvMin + prvHr;
        int currTime;
        int ans=INT_MAX;
        for(int i=1;i<tm.size();i++){
            if(tm[i]==tm[i-1])  return 0;
            int currMin = stoi(tm[i].substr(3,2));
            int currHr = stoi(tm[i].substr(0,2))*60;
            currTime = currMin + currHr;
            int diff = currTime-prvTime;
            prvTime = currTime;
            ans=min(ans,diff);
        }
        currTime = (24*60 - currTime);
        ans=min(ans,currTime + prvMin + prvHr);
        return ans;
    }
};