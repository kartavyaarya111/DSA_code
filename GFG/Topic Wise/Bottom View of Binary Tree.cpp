//Did my self
// But remember that whenever at same height you got another node then take that late comer node at that width

class Solution {
  public:
    void solve(Node *root, int w, int h, map<int,pair<int,int>>& m){
        if(root==NULL)  return;
        
        if (m.find(w) == m.end() || m[w].first <= h) {
            m[w] = {h, root->data};
        }
        
        solve(root->left,w-1,h+1,m);
        solve(root->right,w+1,h+1,m);
    }
    vector <int> bottomView(Node *root) {
        vector<int> ans;
        map<int,pair<int,int>> m;
        solve(root, 0, 0, m);
        for(auto& x:m){
            int value = x.second.second;
            ans.push_back(value);
        }
        return ans;
    }
};