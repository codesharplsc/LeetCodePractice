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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* pDes = head, *p = head, *pPrev = NULL, *pNext, *pPrevheader = NULL;
        
        for (int i = 0; i < n - m; i++)
            pDes = pDes->next;
        
        for (int i = 0; i < m - 1; i++){
            pPrevheader = p;
            p = p->next;
            pDes = pDes->next;
            
        }
        
        pDes = pDes->next;
        pPrev = pDes;
        
        while (p != pDes) {
            pNext = p->next;
            
            p->next = pPrev;
            pPrev = p;
            p = pNext;
        }
        
        if (pPrevheader != NULL)
            pPrevheader->next = pPrev;
        
        if (m != 1)
            return head;
        else
            return pPrev;
        
        
    }
};