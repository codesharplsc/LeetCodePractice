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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> traverseNodes;
        TreeNode * element = root;
        
        while (!traverseNodes.empty() || element != NULL) {
            if (element == NULL) {
                element = traverseNodes.top();
                result.push_back(element->val);
                traverseNodes.pop();
                element = element->right;
            }else {
                traverseNodes.push(element);
                element = element->left;
            }
        }
        return result;
    }
};