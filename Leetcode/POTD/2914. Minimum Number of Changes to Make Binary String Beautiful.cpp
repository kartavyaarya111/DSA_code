//first approach
//it given tle
class Solution {
public:
void solve(string &s, int& ans, int temp, int i, vector<int>& v){
    if(i>=s.length()){
        ans = min(ans,temp); 
        return;
    }
    for(int j=i+1;j<s.length();j+=2){
        int x;
        x = v[j]- (i==0?0:v[i-1]);
        temp += (x==0||x==(j-i+1)?0:x);
        solve(s,ans,temp,j+1,v);
    }
}
    int minChanges(string s) {
        int ans=INT_MAX;
        vector<int> v;
        v.push_back(s[0]=='0'?0:1);
        for(int i=1;i<s.length();i++){
            v.push_back(s[i]=='0'?v.back():v.back()+1);
        }
        solve(s,ans,0,0,v);
        return ans;
    }
};

//then thought of memoization problem but it is difficult to convert
//so taken intuition for youtube
//second approach
//think of only 2 char each time then next two and so on...
class Solution {
public:
    int minChanges(string s) {
        char c=s[0];
        int cnt = 1,ans=0;
        for(int i=1;i<s.length();i++){
            if(cnt%2==0){    
                cnt=1;
                c=s[i];
                continue;
            }else{
                if(s[i]!=c){
                    ans++;
                }
                cnt++;
            }
        } 
        return ans;
    }
};