/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 /*
    First thinking of using BFS or DFS with loop function. However, solved this problem with just recursive call
 */
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        vector<vector<int>> result;
        int sum = 0;
        computeNumber(root, {}, result);
        for (int i = 0; i< result.size(); i++)
            sum += toInt(result[i]);
        
        return sum;
    }
    int toInt(vector<int> & element) {
        int sum = 0;
        int i;
        for (i = 0; i < element.size(); i++)
            if (element[i] != 0)
                break;
                
        for (; i < element.size(); i++) {
            sum = sum*10;
            sum += element[i];
        }
        return sum;
    }
    void computeNumber(TreeNode* root, vector<int> element, vector<vector<int>> &result) {
        if (root == NULL)
            return;
        element.push_back(root->val);
        if (root->left == NULL && root->right == NULL) {
            result.push_back(element);
            return;
        }
        computeNumber(root->left, element, result);
        computeNumber(root->right, element, result);
     
        return;
        
    }
};