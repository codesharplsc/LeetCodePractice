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
    ListNode *detectCycle(ListNode *head) {
        ListNode *pSlow = head, *pFast = head, *p;
        if (head == NULL)
            return NULL;
        while (pFast != NULL && pFast->next != NULL) {
            pFast = pFast->next->next;
            pSlow = pSlow->next;
            
            if (pFast == pSlow) {
                p = head;
                while (p != pFast) {
                    p = p->next;
                    pFast = pFast->next;
                }
                return p;
            }
        }
        return NULL;
    }
};