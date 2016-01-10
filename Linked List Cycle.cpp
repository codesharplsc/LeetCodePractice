/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 /*
 fast pointer
 slow pointer
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode * fast, * slow;
        fast = head;
        slow = head;
        if (head == NULL)
            return false;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
           if (fast == slow) 
                return true;
        }
        return false;
    }
};