//Approach1: Simple done by myself
//used set and map; set stores ordering of count and key name
//map stores key and it's count
//O(logN), space:O(n)
class AllOne {
public:
    unordered_map<string,int> m;
    set<pair<int,string>> s;
    AllOne() {
        
    }
    
    void inc(string key) {
        if(s.find({m[key],key})!=s.end()){
            s.erase({m[key],key});
            s.insert({m[key]+1,key});
        }else{
            s.insert({1,key});
        }
        cout<<key<<" "<<m[key]+1<<endl;
        m[key]++;
    }
    
    void dec(string key) {
        s.erase({m[key],key});
        if(m[key]>1)
            s.insert({m[key]-1,key});
        m[key]--;
        cout<<key<<" "<<m[key]-1<<endl;
        if(m[key]==0)   m.erase(key);
    }
    
    string getMaxKey() {
        if(m.size()==0) return "";
        // cout<<s.begin()->second<<" "<<s.begin()->first<<endl;
        return s.rbegin()->second;
    }
    
    string getMinKey() {
        if(m.size()==0) return "";
        // cout<<s.rbegin()->second<<" "<<s.rbegin()->first<<endl;
        return s.begin()->second;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */




//Approach 2: done using double linked list using stl
//use map to store key and pointer of node where it stores key and count
//O(n), space:O(n)
class AllOne {
public:
    struct Node{
        int count;
        list<string> keys;
        Node* prev;
        Node* next;
        Node(int c):count(c),prev(NULL),next(NULL){}
    };
    unordered_map<string,Node*> m;
    Node* head, *last; 
    void addNode(Node* prvsNode, int val){
        Node* tmp = new Node(val);
        tmp->next=prvsNode->next;
        tmp->prev=prvsNode;
        if(prvsNode->next)  prvsNode->next->prev=tmp;
        prvsNode->next=tmp;
        if(prvsNode==last){
            last=tmp;
        }
    }
    void removeNode(Node* node){
        node->prev->next=node->next;
        if(node->next) node->next->prev=node->prev;
        if(node==last){
            last=node->prev;
        }
        delete(node);
    }

    AllOne() {
        head= new Node(0);
        last=head;
    }
    
    void inc(string key) {
        if(m.find(key)==m.end()){
            if(head->next==NULL || head->next->count!=1){
                addNode(head,1);
            }
            head->next->keys.push_back(key);
            m[key]=head->next;
        }else{
            Node* curr = m[key];
            int currcount = curr->count;
            if(curr->next==NULL || curr->next->count!=currcount+1){
                addNode(curr,currcount+1);
            }
            curr->next->keys.push_back(key);
            m[key]=curr->next;
            curr->keys.remove(key);
            if(curr->keys.empty()){
                removeNode(curr);
            }
        }
    }
    
    void dec(string key) {
        Node* curr  =m[key];
        int currcount = curr->count;
        if(currcount==1){
            m.erase(key);
        }else{
            if(curr->prev->count!=currcount-1){
                addNode(curr->prev,currcount-1);
            }
            curr->prev->keys.push_back(key);
            m[key]=curr->prev;
        }
        curr->keys.remove(key);
        if(curr->keys.empty()){
            removeNode(curr);
        }
    }
    
    string getMaxKey() {
        if(last==head)  return "";
        return last->keys.front();
    }
    
    string getMinKey() {
        if(!head->next)  return "";
        return head->next->keys.front();
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */