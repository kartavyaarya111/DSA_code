//EASY no need to revise


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
class Solution {
public:
    void solve(TreeNode* root, int val, TreeNode* &ans){
        if(root==NULL)  return;
        if(root->val == val){
            ans=root;
            return;
        }
        solve(root->left,val,ans);
        solve(root->right,val,ans);
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* ans=NULL;
        solve(root,val,ans);
        return ans;
    }
};