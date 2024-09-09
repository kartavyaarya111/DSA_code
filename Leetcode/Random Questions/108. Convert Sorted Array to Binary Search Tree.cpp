//Remember the concept that if inorder given then use divide and conquer mid element is root then go to left half and right half.
//done it myself

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
    void solve(vector<int>& nums,int i, int j, TreeNode* root){
        if(i>j) return;
        float temp = (i+j)/2.0;
        int mid=(int)(ceil(temp));
        root->val=nums[mid];
        if(mid-1>=i){
            TreeNode* t = new TreeNode();
            root->left=t;
            solve(nums,i,mid-1,t);
        }
        if(mid+1<=j){
            TreeNode* t = new TreeNode();
            root->right=t;
            solve(nums,mid+1,j,t);
        }
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root=new TreeNode(0);
        TreeNode* ans = root;
        solve(nums,0,nums.size()-1,root);
        return ans;
    }
};