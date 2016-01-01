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
    int minDepth(TreeNode* root) {
        
        if(root ==NULL)
            return 0;
        int result = 0;
        int len;
        vector<TreeNode*> Myqueue;
        Myqueue.push_back(root);
        
        while (!Myqueue.empty()) {
            len = Myqueue.size();
            for (int i = 0; i < len; i++) {
                if (Myqueue[0]->left != NULL)
                    Myqueue.push_back(Myqueue[0]->left);
                if (Myqueue[0]->right != NULL)
                    Myqueue.push_back(Myqueue[0]->right);
                
                if (Myqueue[0]->left == NULL && Myqueue[0]->right == NULL)
                    return result + 1;
                Myqueue.erase(Myqueue.begin());
            }
            result++;
           
        }    
        return result; 
    }
};