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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL) return NULL;
        ListNode *i = head;
        int len=1;
        while(i->next){
            i = i->next;
            len++;
        }
        i->next = head;
        int end = k%len;
        while(len-end>0){
            end++;
            i = i->next;
        }
        ListNode *r = i->next;
        i->next = NULL;
        return r;
    }
};