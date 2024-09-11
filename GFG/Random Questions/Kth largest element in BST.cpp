// Easy question no need to revise

// return the Kth largest element in the given BST rooted at 'root'
class Solution
{
    public:
    void solve(Node *root, int &k, int& ans){
        if(k<=0)    return;
        if(root->right) solve(root->right, k,ans);
        if(--k==0){
            ans=root->data;
            return;
        }
        if(root->left)  solve(root->left,k,ans);
    }
    int kthLargest(Node *root, int K)
    {
        int ans;
        solve(root,K,ans);
        return ans;
    }
};