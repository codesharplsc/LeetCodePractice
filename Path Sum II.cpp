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

    //solution wihout a recursive call, the main point is using a map to identify the time to pop out the element
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        stack<TreeNode* > MyStack;
        
        //This is just for PushFlag's first element after root to succeed the PushFlag[MyStack.top()] = 1 call
        MyStack.push(NULL);
        MyStack.push(root);
        TreeNode *p;
        vector<int> Element;
        vector<vector<int>> result;
        map<TreeNode*,int> PushFlag;
        
        int num_sum = 0;
    
        if(root == NULL)
            return result;
            
        
        while (MyStack.top() != NULL) {
            p = MyStack.top();
            MyStack.pop();
            
            while (PushFlag[p] != 0) {
                num_sum = num_sum - Element[Element.size() - 1];
                Element.erase(Element.end() - 1);
                PushFlag[p]--;
            }
            
            
            Element.push_back(p->val);
            num_sum += p->val;
            
            if (p->right == NULL && p->left == NULL)
                if(num_sum == sum)
                    result.push_back(Element);
                
            //whenever the tree finished visiting its left subtree and right subtree pop it out
            PushFlag[MyStack.top()]++;
            
            //care for pushing right subtree node first cuz it is stack!
            if (p->right != NULL)
                MyStack.push(p->right);
            if (p->left != NULL)
                MyStack.push(p->left);    
        }
        
        return result;
    }
    
};