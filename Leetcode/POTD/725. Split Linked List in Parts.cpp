//Revise it pritty tricky question
//Done myself

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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> v;
        int n = 0;
        ListNode* tmp = head;
        while(tmp!=NULL){
            n++;
            tmp=tmp->next;
        }
        int mod=n%k;
        int sz=n/k;
        if(sz==0)   mod=0;
        while(k--){
            v.push_back(head);
            if(head==NULL)  continue;
            int d = sz;
            if(mod>0){   d+=1;mod--;}
            if(d==0)    d=1;
            while(d--){
                tmp=head;
                head=head->next;
            }
            if(k>0 && tmp!=NULL)   tmp->next=NULL;
        }
        return v;
    }
};