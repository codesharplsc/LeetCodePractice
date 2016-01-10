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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> myStack;
        vector<int> result;
        TreeNode* element;
        if (root == NULL)
            return result;
        myStack.push(root);
        
        while (!myStack.empty()) {
            element = myStack.top();
            myStack.pop();
            result.push_back(element->val);
            
            if (element->right != NULL)
                myStack.push(element->right);
            
            if (element->left != NULL)
                myStack.push(element->left);
        }
        
        return result;
    }
};