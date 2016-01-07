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
    bool hasPathSum(TreeNode* root, int sum) {
        
        return computeSubTree(root, sum , 0);
    }
    
    bool computeSubTree(TreeNode * root, int sum, int num) {
        if (root == NULL)
            return false;
        num += root->val;
        if (num == sum && root->left == NULL && root->right == NULL)
            return true;
            
        return computeSubTree(root->left, sum, num) || computeSubTree(root->right, sum, num);
    }
    
};