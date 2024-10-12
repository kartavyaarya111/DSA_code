//revise
//my first approach use set then found that set will erase repeating elements that leads to wrong answer

// class Solution {
// public:
//     int minGroups(vector<vector<int>>& intervals) {
//         sort(intervals.begin(),intervals.end());
//         set<int> s;
//         for(auto& x:intervals){
//             if(!s.empty() && x[0]>*s.begin()){
//                 cout<<*s.begin()<<":";
//                 s.erase(*s.begin());
//             }
//             s.insert(x[1]);
//             cout<<x[1]<<endl;
//         }
//         return s.size();
//     }
// };

//used priority queue
//now answer works well
class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        priority_queue<int,vector<int>, greater<int>> s;
        for(auto& x:intervals){
            if(!s.empty() && x[0]>s.top()){
                // cout<<s.top()<<":";
                s.pop();
            }
            s.push(x[1]);
            // cout<<x[1]<<endl;
        }
        return s.size();
    }
};