//Easy 

class CustomStack {
public:
    vector<int> v;
    int k;
    CustomStack(int maxSize) {
        k=maxSize;
    }
    
    void push(int x) {
        if(v.size()<k){
            v.push_back(x);
        }
    }
    
    int pop() {
        int top = -1;
        if(v.size()){
            top=v.back();
            v.pop_back();
        }
        return top;
    }
    
    void increment(int k, int val) {
        int mini = k<v.size()?k:v.size();
        for(int i=0;i<mini;i++)
            v[i]+=val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */