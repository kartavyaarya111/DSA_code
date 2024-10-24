//Good question
//2 approaches
//1st: done with many conditions

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
    bool solve(TreeNode* root1, TreeNode* root2){
        if(root1->val != root2->val)    return 0;
        if(!root1->left && !root1->right && !root2->left && !root2->right) return 1;
        else if(!root1->left && !root1->right && (root2->left || root2->right)) return 0;
        else if(!root2->left && !root2->right && (root1->left || root1->right)) return 0;
        else if(root1->left && root1->right && (!root2->left && root2->right)) return 0;
        else if(root1->left && root1->right && (root2->left && !root2->right)) return 0;
        else if(!root1->left && root1->right && (root2->left && root2->right)) return 0;
        else if(root1->left && !root1->right && (root2->left && root2->right)) return 0;
        else if((root1->left && root2->left && root1->left->val==root2->left->val) && (!root1->right && !root2->right)){
            return solve(root1->left, root2->left);    
        }else if((root1->right && root2->right && root1->right->val==root2->right->val) && (!root1->left && !root2->left)){
            return solve(root1->right, root2->right);    
        }else if(root1->left && !root1->right && !root2->left && root2->right && root1->left->val==root2->right->val){
            root1->right=root1->left;
            root1->left=NULL;
            return solve(root1->right, root2->right);    
        }else if(!root1->left && root1->right && root2->left && !root2->right && root1->right->val==root2->left->val){
            root1->left=root1->right;
            root1->right=NULL;
            return solve(root1->left, root2->left);    
        }else if((root1->left->val==root2->left->val) && (root1->right->val==root2->right->val)){
            return solve(root1->left, root2->left) & solve(root1->right,root2->right);
        }else if((root1->left->val==root2->right->val) && (root1->right->val==root2->left->val)){
            swap(root1->left,root1->right);
            return solve(root1->left, root2->left) & solve(root1->right,root2->right);
        }else{
            return 0;
        }
    }
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if(!root1 && !root2)  return 1;
        if((!root1 && root2) || (root1 && !root2))  return 0;
        return solve(root1, root2);
    }
};


//2nd: with help of GPT without various condition, just with recursions

class Solution {
public:
    bool solve(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2) return true; // both are null
        if (!root1 || !root2 || root1->val != root2->val) return false; // one is null or values are different
        
        // Check both configurations: without swap and with swap
        return (solve(root1->left, root2->left) && solve(root1->right, root2->right)) ||
               (solve(root1->left, root2->right) && solve(root1->right, root2->left));
    }

    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        return solve(root1, root2);
    }
};
