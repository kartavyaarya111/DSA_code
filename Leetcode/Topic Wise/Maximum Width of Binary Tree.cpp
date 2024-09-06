//Must revise
//Good concept

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
    #define ull unsigned long long
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,ull>> q;
        q.push({root,0});
        int ans=1;
        while(!q.empty()){
            int h = q.size();
            ull mini = q.front().second, maxi = q.back().second;
            for(int i=0;i<h;i++){
                auto [tmp,z] = q.front();
                q.pop();
                if(tmp->left){    q.emplace(tmp->left,2*z);}
                if(tmp->right){    q.emplace(tmp->right,2*z+1);}
            }
            ans = max(ans, (int)(maxi-mini+1));
        }
        return ans;
    }
};