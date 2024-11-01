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
    int solve(TreeNode* curr, int l, unordered_map<int,pair<int,int>> &m,unordered_map<int,pair<int,int>> &m1){
        if(curr==NULL)  return 0;
        int left = solve(curr->left,l+1,m,m1);
        int right = solve(curr->right,l+1,m,m1);
        m[curr->val]= {l,l + max(left,right)};
        if(m1.find(l)==m1.end()){
            m1[l]={0,0};
        }
        int ht = l + max(left,right);
        if(ht>m1[l].first){
            m1[l]={ht,m1[l].first};
        }else if(ht>m1[l].second){
            m1[l].second=ht;
        }
        return 1+max(left,right);
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        vector<int> ans;
        unordered_map<int,pair<int,int>>m, m1;
        solve(root,0,m,m1);
        for(auto& x:queries){
            int curr = m[x].second;
            int lev = m[x].first;
            if(m1[lev].first==curr){
                if(m1[lev].second==0 && lev!=0){
                    ans.push_back(lev-1);
                }else
                    ans.push_back(m1[lev].second);
            }else{
                ans.push_back(m1[lev].first);
            }
        }
        return ans;
    }
};