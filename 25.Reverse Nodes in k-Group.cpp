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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* startNode = head, *endNode = head,*pPre = head, *pNext,*result = head;
        int IsFirstTime = 1,i;
        
        if(k <= 1 || head == NULL || head->next == NULL)
            return head;
        
       
       
        //at least has 2 elements
        while(startNode!=NULL){
            
            endNode = startNode;
            
            for(i = 1;i<k;i++){
                if(endNode->next == NULL)
                    break;
                endNode = endNode->next;
            }
            //if this is the first time to reverse and there are not enough element in the list
            if(i!=k)
                break;
                
            pNext = endNode->next;
            
            reverseNode(startNode,endNode);
            
            if(IsFirstTime ==1){
                result = endNode;
                IsFirstTime =0;
                pPre = startNode;
            }else{
                pPre->next = endNode;
                pPre =startNode;
                
            }
            startNode->next = pNext;
            startNode = pNext;
            
        }
        
        return result;
    }
    
    void reverseNode(ListNode* start, ListNode* end){
        ListNode * p = start,*pNext= p->next,*pPre = NULL;
        while(p!=end){
            p->next = pPre;
            
            pPre = p;
            p = pNext;
            pNext = p->next;
            
        }
        //the end element has not been changed
        p->next = pPre;
    
    }
    
};