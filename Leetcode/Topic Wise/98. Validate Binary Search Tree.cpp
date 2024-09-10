//Revise the concept that initially we will take mini as -infinity and maxi infinity then on each step we will madify it and check our 
//root value that it lies between that


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
    bool solve(TreeNode* root, long mini, long maxi){
        if(root==NULL)  return true;
        if(root->val<=mini || root->val>=maxi) return false;
        return solve(root->left,mini,root->val) && solve(root->right,root->val,maxi);
    }
    bool isValidBST(TreeNode* root) {
        if(root==NULL)  return true;

        return solve(root,LONG_MIN,LONG_MAX);
    }
};