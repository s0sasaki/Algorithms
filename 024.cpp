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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL||head->next==NULL) return head;
        ListNode *a, *b, *c, *tmp;
        ListNode *tmp_head = new ListNode(0);
        tmp_head->next = head;
        b = tmp_head;
        while(1){
            a = b;
            if(a==NULL) break;
            b = a->next;
            if(b==NULL) break;
            c = b->next;
            if(c==NULL) break;
            tmp = c->next;
            a->next = c;
            c->next = b;
            b->next = tmp;
        }
        return tmp_head->next;
    }
};