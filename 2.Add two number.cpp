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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *l1_p = l1;
        ListNode *l2_p = l2;
        ListNode *result = NULL;
        ListNode *rear = NULL;//rear for the result list
        ListNode *p = NULL;
        
        int val =0;
        int IsOverTen = 0;
        
        while(l1_p!=NULL&&l2_p!=NULL){
            
            val = l1_p->val+l2_p->val+IsOverTen;
            IsOverTen = 0;
            if(val>=10){
                IsOverTen = 1;
                val = val-10;
            }
            p = new ListNode(val);
            
            if(result == NULL){
                result = p;
                rear = result;
            }else{
                rear->next = p;
                rear = p;
            }
            
            l1_p = l1_p->next;
            l2_p = l2_p->next;
            
        }
        
        while(l1_p!=NULL){
            val = l1_p->val+IsOverTen;
            IsOverTen = 0;
            
            if(val>=10){
                IsOverTen = 1;
                val = val-10;
            }
            p = new ListNode(val);
            rear->next = p;
            rear = p;
            
            l1_p = l1_p->next;
        }
        
        while(l2_p!=NULL){
            val = l2_p->val+IsOverTen;
            IsOverTen = 0;
            
            if(val>=10){
                IsOverTen = 1;
                val = val-10;
            }
            p = new ListNode(val);
            rear->next = p;
            rear = p;
            l2_p = l2_p->next;
            
        }
        
        if(IsOverTen==1){
            p = new ListNode(1);
            rear->next = p;
            rear = p;
            
        }
    return result;
        
    }
};