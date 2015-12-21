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
    ListNode* deleteDuplicates(ListNode* head) {
        
        ListNode FakeRoot(0);
        ListNode *p = head, *pPrev = &FakeRoot, *pNext, *q;
        FakeRoot.next =head;
        
        int val;
        
        while (p != NULL) {
            q = p;
            val = p->val;
            
            while (q != NULL && q->val == val)
                q = q->next;
                
            if (q == p->next) {
                pPrev = p;
                p = p ->next;
            }else {
                pPrev = p;
                pPrev->next = q;
    
                p = p->next;
                while (p != NULL && p!= q) {
                    pNext = p->next;
                    free(p);
                    p = pNext;
                }   
            }
                
        }
        return FakeRoot.next;
    }
};