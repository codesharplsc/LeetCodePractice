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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0)
            return NULL;
        
        map<int,int> inorderMap;
        for (int i = 0; i < inorder.size(); i++)
            inorderMap[inorder[i]] = i;
        
        return constructTree(preorder, inorder, 0, preorder.size()-1, 0, inorderMap);
    }
    
    TreeNode* constructTree(vector<int> &preorder, vector<int> &inorder, int start, int end, int start2, map<int,int> &inorderMap) {
        if (start > end)
            return NULL;
        
        int i;
        TreeNode* newNode;
        newNode = new TreeNode(preorder[start]);
        int rootVal = preorder[start];
        //To avoid the loop function, using map instead
        //for (i = start; i <= end && inorder[i] != rootVal; i++);
        i = inorderMap[rootVal] - start2 + start;
        
        newNode->left = constructTree(preorder, inorder, start+1, i, start2, inorderMap);
        newNode->right = constructTree(preorder, inorder, i+1, end, inorderMap[rootVal] + 1,inorderMap);
        
        return newNode;
    }
    
};