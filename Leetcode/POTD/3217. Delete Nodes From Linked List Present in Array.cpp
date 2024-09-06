//Done this question in one go...

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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> s;
        for(auto& x:nums)   s.insert(x);
        while(head!=NULL && s.find(head->val)!=s.end()){
            head=head->next;
        }
        ListNode* temp = head;
        while(temp && temp->next){
            ListNode* ptr = temp->next;
            if(s.find(ptr->val)!=s.end()){
                ptr=ptr->next;
                temp->next=ptr;
            }else{
                temp=temp->next;
            }
        }
        return head;
    }
};