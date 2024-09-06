//Good question
//Don't think much of complexity while sorting just try to code
//Revise

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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        queue<pair<TreeNode*,pair<int,int>>> q;
        map<int,vector<pair<int,int>>> m;
        q.push({root,{0,0}});
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                auto node = q.front().first;
                auto [width,height] = q.front().second;
                q.pop();
                m[width].push_back({height,node->val});
                if(node->left)  q.push({node->left,{width-1,height+1}});
                if(node->right)  q.push({node->right,{width+1,height+1}});
            }
        }
        for(auto& x:m){
            sort(x.second.begin(),x.second.end());
            vector<int> v;
            for(auto &y:x.second){
                v.push_back(y.second);
            }
            ans.push_back(v);
        }
        return ans;
    }
};