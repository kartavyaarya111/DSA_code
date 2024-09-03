//Two line changed from Inorder

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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        while(root!=NULL){
            if(root->left==NULL){
                ans.push_back(root->val);
                root=root->right;
            }else{
                TreeNode* prvs = root->left;
                while(prvs->right && prvs->right!=root){
                    prvs=prvs->right;
                }
                if(prvs->right==NULL){
                    prvs->right=root;
                    ans.push_back(root->val);
                    root=root->left;
                }else{
                    prvs->right=NULL;
                    root=root->right;
                }
            }
        }
        return ans;
    }
};