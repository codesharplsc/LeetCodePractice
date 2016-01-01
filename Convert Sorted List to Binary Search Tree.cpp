/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == NULL)
            return NULL;
        ListNode* p = head, *pNext = p->next;
        vector<int> myNum;
        
        while (p != NULL) {
            myNum.push_back(p->val);
            
            p = pNext;
            if (pNext != NULL)
                pNext = pNext->next;
        }
        
        return sortedArrayToBST(myNum);
    
    }
    
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() == 0)
            return NULL;
        return generateBST(nums, 0, nums.size()-1);
    }
    
    TreeNode* generateBST(vector<int> & nums, int start, int end) {
        if (start > end)
            return NULL;
        int mid = (start + end)/2;
        TreeNode *p = new TreeNode(nums[mid]);
        
        p->left = generateBST(nums, start, mid - 1);
        p->right = generateBST(nums, mid + 1, end);
        
        return p;
        
    }
    
};