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
    ListNode* partition(ListNode* head, int x) {
        ListNode * p = head, *pPrev = NULL, *pLast = head,*Last;
        ListNode * result = NULL;
        ListNode*  q;
        int firstTime = 1;
    
        if (head == NULL)
            return head;
        //Find the first element of the new list
        while (pLast->next != NULL) {
            if (pLast->val < x && firstTime == 1) {
                firstTime = 2;
                result = pLast;
            }
            
            pLast = pLast->next;
        }
        //because we didnt check the last element
        if (result == NULL && pLast->val < x)
            result = pLast;
        
        if (result == NULL)
            return head;
        
        Last = pLast;
           
        while (p != Last) {
            if (p->val < x ) {
                pPrev = p;
                p = p->next;
            }else {
                q = p;
                while (q != Last && q->next->val >= x)
                    q = q->next;
                
                if (pPrev != NULL && q->next != NULL)
                    pPrev ->next = q->next;
                
                pLast->next = p;
                p = q->next;
                q->next = NULL;
                pLast = q; 
                
                if (q == Last)
                    return result;
            } 
        }
        
        if (p->val >= x) {
            if (p->next != NULL)
                pPrev->next = p->next;
            pLast->next = p;
            p->next =NULL;
        }
        return result; 
    }
};