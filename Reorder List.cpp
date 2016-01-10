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
    void reorderList(ListNode* head) {
        ListNode* pHalf = head, *p = head,*q, *pNext, *qNext;
        int len = 0, i, j;
        
        if (head == NULL)
            return;
        while (p != NULL) {
            p = p->next;
            len++;
        }
        
        for (i = 0; i < (len/2); i++) 
            pHalf = pHalf->next;
            
        q = reverseOrder(pHalf);
        p = head;
        while (q != NULL) {
            pNext = p->next;
            qNext = q->next;
            
            p->next = q;
            q->next = pNext;
            
            p = pNext;
            q = qNext;
        }
        //This is in case the odd and even number of the total lengh of the list
        if (p != NULL)
            p->next = NULL;
            
        return;
    }
    
    ListNode* reverseOrder(ListNode *p) {
        if (p == NULL || p->next == NULL)
            return p;
            
        ListNode* pPrev = NULL, *pNext;
        while (p != NULL) {
            pNext = p->next;
            
            p->next = pPrev;
            pPrev = p;
            p = pNext;
        }
        return pPrev;
    
    } 
    
    
};