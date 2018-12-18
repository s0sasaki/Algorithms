/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode r(0);
        ListNode* p = &r;
        while(l1!=NULL && l2!=NULL){
            if(l1->val < l2->val) {
                p->next = new ListNode(l1->val);
                p = p->next;
                l1 = l1->next;
            }else{
                p->next = new ListNode(l2->val);
                p = p->next;
                l2 = l2->next;
            }
        }
        if(l1==NULL) p->next = l2;
        if(l2==NULL) p->next = l1;
        return r.next;
    }
};