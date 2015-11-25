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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode * p = head;
        ListNode * pNext = head;
        int len = 0;
        
        if (head == NULL || head->next == NULL)
            return head;
            
        
        while (p != NULL) {
            p = p->next;
            len++;
        }
        
        k = k%len;
        
        for (int i = 0 ; i < k; i++)
            pNext = pNext->next;
        
        p = head;
        while (pNext->next != NULL) {
            p = p->next;
            pNext = pNext->next;
        }
        pNext->next = head;
        head = p->next;
        p->next = NULL;
        return head;
        
    }
};