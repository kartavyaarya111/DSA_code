struct Node{
    int data;
    Node* next,*prvs;
    Node(int val){
        data =val;
        next=NULL;
        prvs=NULL;
    }
};
class MyCircularDeque {
public:
    int sz,K;
    Node*front,*rear;
    MyCircularDeque(int k) {
        sz=0;K=k;
        front =NULL;
        rear=NULL;
    }  
    bool insertFront(int value) {
        if(sz<K){
            Node* tmp = new Node(value);
            if(sz==0){
                front=tmp;
                rear=tmp;
            }else{
                tmp->next=front;
                front->prvs=tmp;
                front=tmp;
            }
            sz++;
            return true;
        }
        return false;
    }
    
    bool insertLast(int value) {
        if(sz<K){
            Node* tmp = new Node(value);
            if(sz==0){
                front=tmp;
                rear=tmp;
            }else{
                rear->next=tmp;
                tmp->prvs=rear;
                rear=tmp;
            }
            sz++;
            return true;
        }
        return false;
    }
    
    bool deleteFront() {
        if(sz==0)   return false;
        Node*tmp=front;
        if(front==rear) rear=NULL;
        front=front->next;
        if(front)   front->prvs=NULL;
        delete(tmp);
        sz--;
        return true;
    }
    
    bool deleteLast() {
        if(sz==0)   return false;
        Node*tmp=rear;
        if(front==rear) front=NULL;
        rear=rear->prvs;
        if(rear)    rear->next=NULL;
        delete(tmp);
        sz--;
        return true;
    }
    
    int getFront() {
        if(front!=NULL) return front->data;
        return -1;
    }
    
    int getRear() {
        if(rear!=NULL)  return rear->data;
        return -1;
    }
    
    bool isEmpty() {
        if(sz==0)   return true;
        return false;
    }
    
    bool isFull() {
        if(sz==K)   return true;
        return false;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */