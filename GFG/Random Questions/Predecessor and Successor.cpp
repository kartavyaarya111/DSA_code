//very good question must revise


class Solution
{
    public:
    void solve1(Node*root,Node*& suc, int &key){
        while(root){
            if(key>=root->key){
                root=root->right;
            }else{
                suc=root;
                root=root->left;
            }
        }
    }
    void solve2(Node*root,Node*& pre, int &key){
        while(root){
            // cout<<root->key<<" ";
            if(key<=root->key){
                root=root->left;
            }else{
                pre=root;
                root=root->right;
            }
        }
    }
    
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        solve1(root,suc,key);
        solve2(root,pre,key);
    }
};