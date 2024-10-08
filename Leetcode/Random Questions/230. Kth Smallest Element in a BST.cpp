//Easy Question no need to revise


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
    void solve(TreeNode* root, int &k, int &ans){
        if(k==0)    return;
        if(root->left)  solve(root->left,k,ans);
        if(k==0)    return;
        if(--k == 0){
            ans =root->val;
            return;
        }
        if(root->right) solve(root->right,k,ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans;
        solve(root,k,ans);
        return ans;
    }
};