//USING PRIORITY QUEUE
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here 
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> v(V,1e9);
        v[S]=0;
        pq.push({0,S});
        while(!pq.empty()){
            auto x = pq.top();
            pq.pop();
            for(const auto& y:adj[x.second]){
                int z=x.first+y[1];
                if(z<v[y[0]]){
                    v[y[0]]=z;
                    pq.push({z,y[0]});
                }
            }
        }
        return v;
    }
};


//USING SET
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here 
        set<pair<int,int>> pq;
        vector<int> v(V,1e9);
        v[S]=0;
        pq.insert({0,S});
        while(!pq.empty()){
            auto x = *(pq.begin());
            int node = x.second;
            int dis = x.first;
            pq.erase(x);
            for(const auto& y:adj[x.second]){
                int z=dis+y[1];
                if(z<v[y[0]]){
                    if(v[y[0]]!=1e9)    pq.erase({v[y[0]],y[0]});
                    v[y[0]]=z;
                    pq.insert({z,y[0]});
                }
            }
        }
        return v;
    }
};