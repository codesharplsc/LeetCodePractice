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
    bool isBalanced(TreeNode* root) {
       if (computeDepth(root) == -1)
            return false;
       return true;
    }
  
  
    
    int computeDepth(TreeNode* root) {
        int leftDepth, rightDepth;
        if (root == NULL)
            return 0;
            
        leftDepth = computeDepth(root->left);
        if (leftDepth == -1)
            return -1;
        rightDepth = computeDepth(root->right);
        
        if (rightDepth == -1)
            return -1;
        
        if(leftDepth - rightDepth > 1 || rightDepth - leftDepth > 1)
            return -1;
        
        return 1 + (leftDepth > rightDepth?leftDepth:rightDepth);
    }
};