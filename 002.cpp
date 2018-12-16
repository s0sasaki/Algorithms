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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *r = new ListNode(0);
        ListNode *head = r;
        int c=0;
        while(l1!=NULL||l2!=NULL||c!=0){
            if(l1==NULL&&l2==NULL){
                r->next = new ListNode(c);
                c = 0;
            }else if(l1==NULL){
                r->next = new ListNode((l2->val + c)%10);
                r = r->next;
                c = (l2->val + c)/10;
                l2 = l2->next;
            }else if(l2==NULL){
                r->next = new ListNode((l1->val + c)%10);
                r = r->next;
                c = (l1->val + c)/10;
                l1 = l1->next;
            }else{
                r->next = new ListNode((l1->val + l2->val + c)%10);
                r = r->next;
                c = (l1->val + l2->val + c)/10;
                l1 = l1->next;
                l2 = l2->next;
            }
        }
        return head->next;
    }
};