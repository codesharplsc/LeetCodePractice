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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        vector<ListNode*> NewLists;
        ListNode* NewTmp;
        int i = 0;
        int len = lists.size();
        int mid = len%2?len/2:len/2-1;
        
        if(lists.size() == 0)
            return NULL;
        // Here is a quick tip to merge. Merge the first and the last element and store them into the list. Will result in a total O(n*k*log(k))
        //dont go merge the neghiboring lists!!!!!!!
        while(len !=1){
            
            for(int i = 0;i<=mid;i++)
                if(i != len-i-1){
                    NewTmp = mergeTwoList(lists[i],lists[len-1-i]);
                    lists[i] = NewTmp;
                }
            len = mid+1;
            mid = len%2?len/2:len/2-1;
        }
        
        return lists[0];
        
    }
    
    ListNode* mergeTwoList(ListNode *l1, ListNode*l2){
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