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
        int val;
        ListNode* p = head,*pPrev;
        
        ListNode FakeRoot(0);
        FakeRoot.next = head;
        
        pPrev = &FakeRoot;
        ListNode *q,*pNext;
        
        while (p != NULL){
            
            q = p;
            val = p->val;
            while (q != NULL && q->val == val)
                q = q->next;
            
            if (q == p->next) {
                pPrev = p;
                p = p->next;
            }else {
                pPrev->next = q;
            
                //free all the nodes between them 
                while (p != NULL && q != p) {
                    pNext = p->next;
                    free(p);
                    p = pNext;
                }
            }
           
        }
        return FakeRoot.next;
    }
};