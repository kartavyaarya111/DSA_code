//first check whether current interval overlapping with intervals in doubleL 
//if not then check if it is overlapping with single intervals if yes then push it in doublL
class MyCalendarTwo {
public:
    vector<pair<int,int>> doubleL,singleL;
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        for(auto&x :doubleL){
            if(max(x.first,start)<min(x.second,end))
                return false;
        }
        for(auto&x :singleL){
            if(max(x.first,start)<min(x.second,end))
                doubleL.push_back({max(x.first,start),min(x.second,end)});
        }
        singleL.push_back({start,end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */