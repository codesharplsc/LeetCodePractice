/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 // Two pointer points to two list, find the smaller one to add in the new List
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* p1 = l1, *p2 = l2;
        ListNode* pPre = NULL;
        
        if(l1 == NULL)
            return l2;
        
        while(p1!=NULL&&p2!=NULL){
            if(p1->val<p2->val){
                pPre = p1;
                p1 = p1->next;
            }else{
                if(pPre != NULL){
                    pPre->next = p2;
                    p2=p2->next;
                    
                    pPre->next->next = p1;
                    pPre = pPre->next;
                }else{
                    l1 = p2;
                    p2=p2->next;
                    pPre = l1;
                    pPre->next = p1;
                }
            }
        }
        
        if(p2!= NULL)
            pPre->next = p2;
        
        return l1;
    }
};