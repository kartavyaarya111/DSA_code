// Revise it
//See the approach but before that try yourself

class MyCalendar {
public:
    vector<pair<int,int>> v;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        end-=1;
        if(!v.size())   v.push_back({start,end});
        else{
            int left=0,right=v.size()-1;
            while(left<=right){
                int mid = left+(right-left)/2;
                if(v[mid].second<start){
                    // if(start>v[mid].second){
                        left=mid+1;
                    // }else{
                    //     return false;
                    // }
                }else if(v[mid].first>end){
                    // if(end<v[mid].first){
                        right=mid-1;
                    // }else{
                    //     return false;
                    // }
                }else{
                    return false;
                }
                // v.push_back({start,end});
                // // cout<<start <<":"<<end<<endl;
                // sort(v.begin(),v.end());
                // // for(auto &x:v)  cout<<x.first<<":"<<x.second<<" ";
                // cout<<endl;
                // After the binary search, `left` is the position where the new interval can be inserted
            }
            // Check adjacent intervals
                if ((left > 0 && v[left - 1].second >= start) || 
                    (left < v.size() && v[left].first <= end)) {
                    return false; // There's an overlap with the adjacent interval
                }
                
                // If no overlap, insert the new booking
                v.insert(v.begin() + left, {start, end});
        }
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */