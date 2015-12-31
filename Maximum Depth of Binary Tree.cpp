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
    int maxDepth(TreeNode* root) {
        queue<TreeNode*> myQueue;
        int depth = 0;
        int nodeNum;
        TreeNode *p;
        
        if (root == NULL)
            return 0;   
        myQueue.push(root);
        while (!myQueue.empty()) {
            depth++;
            nodeNum = myQueue.size();
            for (int i = 0; i < nodeNum; i++) {
                p = myQueue.front();
                
                if (p->left != NULL)
                    myQueue.push(p->left);
                if (p->right != NULL)
                    myQueue.push(p->right);
                myQueue.pop();    
            }
        }
        return depth;
        
    }
};