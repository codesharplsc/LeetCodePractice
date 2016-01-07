/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
    
public:
    void connect(TreeLinkNode *root) {
        queue<TreeLinkNode*> Myqueue;
        TreeLinkNode* element;
        int num;
        
        if(root == NULL)
            return;
              
        Myqueue.push(root);
        
        while (!Myqueue.empty()) {
            num = Myqueue.size();
            for (int i  = 0 ; i < num; i++) {
                element = Myqueue.front();
                
                if (element->left != NULL)
                Myqueue.push(element->left);
                
                if (element->right != NULL)
                Myqueue.push(element->right);
                
                Myqueue.pop();
                if (i != num - 1)
                    element->next = Myqueue.front();
            }
        }
        return;
    }
};