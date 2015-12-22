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
    vector<TreeNode*> generateTrees(int n) {
        
        if (n == 0)
            return {};
        return generateTree(1, n);
    }
    
    vector<TreeNode*> generateTree(int start, int end) {
        TreeNode *root = NULL;
        vector<TreeNode*> newNodes;
        vector<TreeNode*> leftNodes;
        vector<TreeNode*> rightNodes;
        
        if (start > end)
            return {NULL};
        
        if (start == end) {
            root = new TreeNode(start);
            newNodes.push_back(root);
            return newNodes;
        }
        
        for (int i = start; i <= end; i++) {
            leftNodes = generateTree(start, i-1);
            rightNodes = generateTree(i+1,end);
            
            for (int j = 0; j < leftNodes.size(); j++)
                for (int k = 0; k < rightNodes.size(); k++) {
                    root = new TreeNode(i);
                    root->left = leftNodes[j];
                    root->right = rightNodes[k];
                    newNodes.push_back(root);
                }
        }
        return newNodes;    
    }
};