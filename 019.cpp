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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* rec[n+1];
        for(int i=0;i<n+1;i++) rec[i]=NULL;
        rec[n] = head;
        while(rec[n]->next){
            for(int i=0;i<n;i++) rec[i]=rec[i+1];
            rec[n]=rec[n]->next;
        }
        if(rec[0]==NULL) return head->next;
        if(n<2) rec[0]->next = NULL;
        else rec[0]->next = rec[2];
        return head;
    }
};