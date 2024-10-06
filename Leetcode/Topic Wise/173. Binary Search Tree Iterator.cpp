//Revise the approach

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
public:
    //  rt;
    stack<TreeNode*> s;
    BSTIterator(TreeNode* root) {
        while(root){
            s.push(root);
            root=root->left;
        }
    }
    
    int next() {
        int z= s.top()->val;
        TreeNode* rt = s.top();
        s.pop();
        rt=rt->right;
        while(rt){
            s.push(rt);
            rt=rt->left;
        }
        return z;
    }
    
    bool hasNext() {
        if(s.empty())   return 0;
        return 1;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */


