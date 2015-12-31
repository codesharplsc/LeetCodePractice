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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() == 0 || postorder.size() == 0)
            return NULL;
        map<int,int> inorderMap;
        for (int i  = 0; i < inorder.size(); i++)
            inorderMap[inorder[i]] = i;
        
        return generateTree(inorder, postorder, 0, inorder.size()-1, 0, inorderMap);
     
        
    }
    TreeNode* generateTree(vector<int>& inorder, vector<int>& postorder, int start, int end, int start2, map<int,int>& inorderMap) {
        if (start > end)
            return NULL;
        int i, rootVal;
        TreeNode *root = new TreeNode(postorder[end]);
        rootVal = root->val;
        
        i = inorderMap[rootVal];
        
        root->left = generateTree(inorder, postorder, start, start + (i - start2 - 1), start2, inorderMap);
        root->right = generateTree(inorder, postorder, start + (i - start2), end-1, i + 1, inorderMap);
        
        return root;
        
    }
};