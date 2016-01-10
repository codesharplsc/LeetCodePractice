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
    ListNode* insertionSortList(ListNode* head) {
        ListNode *pStart = head, *pNext, *p, *pSorted, *pSortedPrev;
        if (head == NULL)
            return NULL;
            
        p = head->next;
        head->next = NULL;
        
        while (p != NULL) {
            pNext = p->next;
            
            pSorted = pStart;
            pSortedPrev = NULL;
            //Find a position to insert the node
            while (pSorted != NULL) {
                if (pSorted->val > p->val) {
                    if (pSortedPrev == NULL) {
                        pStart = p;
                        p->next = pSorted;
                        
                    }else {
                        pSortedPrev->next = p;
                        p->next = pSorted;
                    }
                    
                    break;
                }
                pSortedPrev = pSorted;
                pSorted = pSorted->next; 
            }
            //if it is greater than all the element in the sorted list
            if (pSorted == NULL) {
                pSortedPrev->next = p;
                p->next = NULL;
            }
    
            p = pNext;
        }
        return pStart;
    }
};