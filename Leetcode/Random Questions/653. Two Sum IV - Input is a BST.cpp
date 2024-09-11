//MUST REVISE
//Approach is very new


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
class solve{
    public:
    stack<TreeNode*> st;
    bool reverse = true;
    // if reverse is true i.e. before stack
    // if reverse is false i.e. next stack
    solve(TreeNode* root, bool isReverse){
        reverse = isReverse;
        pushAll(root);
    }
    bool hasNext(){
        return !st.empty();
    }
    int next(){
        TreeNode* tmp = st.top();
        st.pop();
        if(!reverse){
            pushAll(tmp->right);
        }else{
            pushAll(tmp->left);
        }
        return tmp->val;
    }
    void pushAll(TreeNode* root){
        while(root){
            st.push(root);
            if(!reverse)
                root=root->left;
            else
                root=root->right;
        }
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        solve l(root,0);
        solve r(root,1);
        int i = l.next();
        int j= r.next();
        while(i<j){
            if(i+j==k)    return 1;
            if(i+j<k)   i=l.next();
            else    j=r.next();
        }
        return 0;
    }
};