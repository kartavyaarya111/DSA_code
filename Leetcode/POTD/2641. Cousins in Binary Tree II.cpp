//revise
//did myself

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
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<pair<TreeNode*,TreeNode*>> q;
        q.push({NULL,root});
        int sum=0;
        while(!q.empty()){
            int sz=q.size(),tmp=0,prvs=0;
            while(sz--){
                auto [par,curr] = q.front();
                cout<<curr->val<<" ";
                if(par)cout<<par->val<<endl;
                q.pop();
                int sum1=0;
                if(par!=NULL){
                    if(par->left)sum1+=(par->left->val);
                    if(par->right)sum1+=(par->right->val);
                }
                // cout<<curr->val<<" "<<sum1<<" "<<sum<<" "<<sz<<endl;
                if(par && par->left && curr==par->left){
                    prvs= par->left->val;
                    curr->val = sum1!=sum?sum-sum1:0;
                }else{
                    if(par && par->left)sum1 = sum1-par->left->val + prvs; 
                    curr->val = sum1!=sum?sum-sum1:0;
                    prvs= 0;
                }
                if(curr->left){tmp+=curr->left->val;    q.push({curr,curr->left});}
                if(curr->right){tmp+=curr->right->val;    q.push({curr,curr->right});}
            }
            sum=tmp;
        }
        return root;
    }
};