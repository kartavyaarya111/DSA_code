//DONE in 2 approaches
//1.DFS
//2.BFS
//Revise DFS appoach

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void solve(Node* root){
        if(!root || !root->left)    return;
        root->left->next=root->right;
        if(root->next)    root->right->next=root->next->left;
        solve(root->left);
        solve(root->right);
    }
    Node* connect(Node* root) {
        solve(root);
        return root;
    }
};

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL)  return root;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                Node* tp = q.front();
                q.pop();
                if(i==sz-1) tp->next==NULL;
                else    tp->next=q.front();
                if(tp->left){ q.push(tp->left);q.push(tp->right);}
            }
        }
        return root;
    }
};