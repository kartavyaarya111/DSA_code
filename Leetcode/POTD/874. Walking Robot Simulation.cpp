//Good question
//I took a lot time to solve this problem

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int ans=0;
        vector<pair<int,int>> dir = {{-1,0},{0,1},{1,0},{0,-1}};
        int pos = 1;
        unordered_set<string> s;
        for(auto& z:obstacles){
            string temp = to_string(z[0]) + ('_') + to_string(z[1]);
            s.insert(temp);
        }
        pair<int,int> curr ={0,0};
        for(auto& z:commands){
            if(z==-1){
                pos++;
            }else if(z==-2){
                pos--;
            }else{
                for(int i=1;i<=z;i++){
                    int a = curr.first + dir[pos].first;
                    int b = curr.second + dir[pos].second;
                    string st = to_string(a)+('_')+to_string(b);
                    if(s.find(st)!=s.end()){
                        break;
                    }else{
                        ans= max(ans, a*a+b*b);
                        curr={a,b};
                    }
                }
            }
            if(pos==-1){
                pos=3;
            }else{
                pos%=4;
            }
        }
        return ans;
    }
};