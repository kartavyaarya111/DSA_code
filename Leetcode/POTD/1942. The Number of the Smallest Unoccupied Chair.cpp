//Revise

class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        vector<vector<int>> v;
        int n=times.size();
        for(int i=0;i<n;i++){
            v.push_back({times[i][0],times[i][1],i});
        }
        sort(v.begin(),v.end());
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<n;i++)    pq.push(i);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> last;
        for(int i=0;i<n;i++){
            while(!last.empty() && last.top().first<=v[i][0]){
                pq.push(last.top().second);
                last.pop();
            }
            last.push({v[i][1],pq.top()});
            int top=pq.top();
            pq.pop();
            if(v[i][2]==targetFriend) return top;
        }
        return -1;
    }
};