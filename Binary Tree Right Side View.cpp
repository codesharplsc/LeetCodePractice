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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        int len;
        vector<TreeNode*> Myqueue;
        Myqueue.push_back(root);
        if (root == NULL)
            return {};
        while (!Myqueue.empty()) {
            len = Myqueue.size();
            result.push_back(Myqueue[len - 1]->val);
            for (int i = 0 ; i < len; i++) {
                if (Myqueue[0]->left != NULL)
                    Myqueue.push_back(Myqueue[0]->left);
                if (Myqueue[0]->right != NULL)
                    Myqueue.push_back(Myqueue[0]->right);
                
                Myqueue.erase(Myqueue.begin());
            }
        }
        return result;
        
    }
};