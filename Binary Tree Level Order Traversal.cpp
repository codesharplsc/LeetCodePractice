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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> result;
        
        int len;
        vector<TreeNode*> Myqueue;
        
        Myqueue.push_back(root);
        
        if (root == NULL)
            return result;
        
        while (!Myqueue.empty()) {
            vector<int> ResultElement;
            len = Myqueue.size();
            for (int i = 0 ; i < len; i++){
                ResultElement.push_back(Myqueue[0]->val);
                if (Myqueue[0]->left != NULL)
                    Myqueue.push_back(Myqueue[0]->left);
                if (Myqueue[0]->right != NULL)
                    Myqueue.push_back(Myqueue[0]->right);   
                Myqueue.erase(Myqueue.begin());
                
            }
            result.push_back(ResultElement);
            
        }
        
        return result;  
    }
};