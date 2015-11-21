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
        
        if(head == NULL)
            return NULL;
            
        if(head->next == NULL)
            return head;
            
        ListNode* pPre = head, *p=head, *pNext= p->next, *pDNext = pNext->next, *NewRoot = head->next;
        
        while(1){
            pPre->next = pNext;
            pNext->next = p;
            p->next = pDNext;
        
            if(pDNext == NULL)
                break;
            if(pDNext->next == NULL)
                break;
                
            pPre = p;
            p = pDNext;
            pNext = p->next;
            pDNext = pNext->next;
        }
        
        return NewRoot;
        
        
    }
};