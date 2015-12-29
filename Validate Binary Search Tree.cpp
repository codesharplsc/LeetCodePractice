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
    bool isValidBST(TreeNode* root) {
        //Using LLONG_MIN to escape corner cases!!!
        return traverseTree(root, LLONG_MIN, LLONG_MAX);
        
    }
    bool traverseTree(TreeNode * root, long long low, long long high) {
        bool leftTree = true, rightTree = true;
        if (root == NULL)
            return true;
       
        if (root->val <= low || root->val >=high)
                return false;           
        
        leftTree = traverseTree(root->left, low, root->val);
        rightTree = traverseTree(root->right, root->val, high);
        
        if (leftTree == false || rightTree == false)
            return false;
        else
            return true;   
    }  
};