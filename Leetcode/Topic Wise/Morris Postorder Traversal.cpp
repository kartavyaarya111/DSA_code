//opposite of pre order
//atlast done reverse


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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>  ans;
        while(root){
            if(root->right==NULL){
                ans.push_back(root->val);
                root=root->left;
            }else{
                TreeNode* prvs = root->right;
                while(prvs->left && prvs->left!=root){
                    prvs=prvs->left;
                }
                if(prvs->left==NULL){
                    prvs->left=root;
                    ans.push_back(root->val);
                    root=root->right;
                }else{
                    prvs->left=NULL;
                    root=root->left;
                }
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};