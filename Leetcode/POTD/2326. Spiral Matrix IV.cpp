/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m,vector<int>(n,-1));
        pair<int,int> p={0,1},curr={0,-1};
        m--;
        while(head && (n>0 || m>0)){
            int dir = (p.first==0)?n:m;
            while(dir--){
                curr.first+=p.first;
                curr.second+=p.second;
                auto [i,j]=curr;
                ans[i][j]=head->val;
                head=head->next;
                if(head==NULL)  break;
            }
            if(p.first==0)  n--;
            else    m--;
            int tmp=p.first;
            p.first=(p.second);
            p.second = tmp*(-1);
        }
        return ans;
    }
};