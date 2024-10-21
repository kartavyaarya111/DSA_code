//revise
//previously done it with recursion resulted in MLE
//should follow greedy using heap because we need to take highest occuring element first
//use answer variable to store correct answer in one go of while loop

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>> pq;
        if(a)   pq.push({a,'a'});
        if(b)   pq.push({b,'b'});
        if(c)   pq.push({c,'c'});
        string ans="",tmp="";
        while(!pq.empty()){
            auto [num,c] = pq.top();
            pq.pop();
            int len=ans.length();
            if(ans.length()>=2 && ans[len-2]==c && ans[len-1]==c){
                if(!pq.empty()){
                    auto [num1,c1] = pq.top();
                    pq.pop();
                    ans+=c1;
                    num1-=1;
                    if(num1)    pq.push({num1,c1});
                    pq.push({num,c});
                }
            }else{
                ans+=c;
                num-=1;
                if(num)    pq.push({num,c});
            }
        }
        return ans;
    }
};