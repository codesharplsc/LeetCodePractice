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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        int len;
        vector<TreeNode*> Myqueue;
        vector<int> resultElement;
        Myqueue.push_back(root);
        if (root == NULL)
            return {};
       
        while (!Myqueue.empty()) {
            resultElement.clear();
            len = Myqueue.size();
            for (int i = 0; i < len; i++) {
                if (Myqueue[0]->left != NULL)
                    Myqueue.push_back(Myqueue[0]->left);
                    
                if (Myqueue[0]->right != NULL)
                    Myqueue.push_back(Myqueue[0]->right);
                    
                resultElement.push_back(Myqueue[0]->val);
                Myqueue.erase(Myqueue.begin());
            }
            result.push_back(resultElement);
        }
        reverse(result.begin(), result.end()); 
        return result;
    }
};