/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 /*
 1.Set leftSubTree to NULL
 2.check if there is no leftTree
 
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        
        moveSubTree(root);
        return;
    }
    
    TreeNode * moveSubTree(TreeNode* root) {
        
        TreeNode* rightLast;
        TreeNode* leftLast;
        if (root == NULL)
            return NULL;
        if (root->left == NULL && root->right == NULL)
            return root;
        
        leftLast = moveSubTree(root->left);
        rightLast = moveSubTree(root->right);
        
        if (leftLast != NULL) {
            leftLast->right = root->right;
            root->right = root->left;
        }
        
        root->left = NULL;  
        if (rightLast != NULL)
            return rightLast;
            
        return leftLast;
        
        
    }
};