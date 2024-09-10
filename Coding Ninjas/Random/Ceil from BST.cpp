//No need to revise
//Did myself
#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

    class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
        
        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if (left) {
              delete left;
            }
            if (right) {
              delete right;
            }
        }
    };

************************************************************/

int findCeil(BinaryTreeNode<int> *root, int X){
    int ans = -1;
    while(root){
        if(X<=root->data)    ans=root->data;
        if(X==root->data){
            break;
        }else if(X>root->data){
            root=root->right;
        }else{
            root=root->left;
        }
    }
    return ans;
}