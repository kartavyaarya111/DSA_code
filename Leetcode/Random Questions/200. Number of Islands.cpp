//BFS approach/done myself

class Solution {
public:
    int m,n;
    void solve(vector<vector<char>>& grid,int x, int y,vector<pair<int,int>>& ax){
        queue<pair<int,int>> q;
        q.push({x,y});
        grid[x][y]='0';
        while(!q.empty()){
            auto [a,b]=q.front();
            q.pop();
            for(auto& [i,j]:ax){
                int newi = a+i, newj=b+j;
                if(newi<0 || newj<0 || newi>=m || newj>=n || grid[newi][newj]=='0')   continue;
                grid[newi][newj]='0';
                q.push({newi,newj});
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        m=grid.size(),n=grid[0].size();
        int ans=0;
        vector<pair<int,int>> ax = {{0,1},{1,0},{0,-1},{-1,0}};
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    ans++;
                    solve(grid,i,j,ax);
                }
            }
        }
        return ans;
    }
};