//Done myself.
//No need to revise.

#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
void solve(TreeNode<int> * root, int X, int& ans){
    if(root==NULL)  return;
    while(root){
        if(root->val<=X)
        ans =root->val;
        if(root->val==X){
            break;
        }
        if(X>root->val){
            root=root->right;
        }else{

            root=root->left;
        }
    }
}
int floorInBST(TreeNode<int> * root, int X)
{
    int ans =0;
    solve(root,X,ans);
    return ans;
}