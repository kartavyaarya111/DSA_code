//Based on Dijkstra's Algorithm
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int,double>>> v(n);
        for(int i=0;i<edges.size();i++){
            v[edges[i][0]].push_back({edges[i][1],succProb[i]});
            v[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        vector<double> djk(n,0.0);
        djk[start]=1;
        priority_queue<pair<double,int>> pq;
        pq.push({1.0,start});
        while(!pq.empty()){
            auto [dis,node]=pq.top();
            pq.pop();
            for(auto& x:v[node]){
                if(djk[x.first]<dis*x.second){
                    djk[x.first]=dis*x.second;
                    pq.push({djk[x.first],x.first});
                }
            }
        }
        if(djk[end]==0.0){
            return 0.0;
        }
        return djk[end];
    }
};