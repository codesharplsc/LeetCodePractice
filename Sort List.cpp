/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
 Two ways quickSort MergeSort.
*/
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        
        return sort(head);      
    } 
    
    ListNode* sort(ListNode* head) {
        ListNode *head2;
        
        if (head == NULL || head->next == NULL)
            return head;
        ListNode* pFast = head, *pSlow = head;
        while (pFast->next != NULL && pFast->next->next != NULL) {
            pFast = pFast->next->next;
            pSlow = pSlow->next;
        }
        head2 = pSlow->next;
        pSlow->next = NULL;
           
        head = sort(head);  
        head2 = sort(head2);  
        return mergeTwoLists(head, head2);  
    }
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* p1 = l1, *p2 = l2;
        ListNode* pPre = NULL;
        
        if (l1 == NULL)
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