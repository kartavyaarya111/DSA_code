//good question
// I did myself

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){80
        data = x;
        left = right = NULL;
    }
};
*/

class Solution{
    public:
    //Function to check whether all nodes of a tree have the value 
    //equal to the sum of their child nodes.
    bool ans;
    void solve(Node*root){
        if(root==NULL)  return;
        if(root->left==NULL && root->right==NULL)   return;
        int l = 0;
        int r = 0;
        if(root->left)  l=root->left->data;
        if(root->right)  r=root->right->data;
        if((l+r)!=root->data){  
            ans=0;
            return;
        }
        solve(root->left);
        solve(root->right);
    }
    int isSumProperty(Node *root)
    {
     // Add your code here
        ans = 1;
        solve(root);
        return ans;
    }   
};