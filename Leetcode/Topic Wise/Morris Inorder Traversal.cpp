//Revise it
//It's time complexity O(n)
//No space complexity

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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        while(root){
            if(root->left){
                TreeNode* prvs = root->left;
                while(prvs->right!=NULL && prvs->right!=root){
                    prvs=prvs->right;
                }
                if(prvs->right==NULL){
                    prvs->right=root;
                    root=root->left;
                }else{
                    prvs->right=NULL;
                    ans.push_back(root->val);
                    root=root->right;
                }
            }else{
                ans.push_back(root->val);
                root=root->right;
            }
        }
        return ans;
    }
};