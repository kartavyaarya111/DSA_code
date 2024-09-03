//Did myself, no need to revise

class Solution {
  public:
    void solve(Node* root, vector<vector<int>> &ans, vector<int> &v){
        if(root==NULL)  return;
        v.push_back(root->data);
        if(root->left==NULL && root->right==NULL){
            ans.push_back(v);
            v.pop_back();
            return;
        }else{
            solve(root->left, ans, v);
            solve(root->right, ans, v);
        }
        v.pop_back();;
    }
    vector<vector<int>> Paths(Node* root) {
        vector<vector<int>> ans;
        vector<int> v;
        solve(root,ans,v);
        return ans;
    }
};