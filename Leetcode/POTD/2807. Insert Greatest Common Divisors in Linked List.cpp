//done myself no need to revise

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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head==NULL || head->next==NULL)  return head;
        ListNode* prv =head,*ans=head;
        head=head->next;
        while(head!=NULL){
            ListNode* t = new ListNode(__gcd(prv->val,head->val));
            prv->next=t;
            t->next=head;
            prv=head;
            head = head -> next;
        }
        return ans;
    }
};