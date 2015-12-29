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
    bool isSymmetric(TreeNode* root) {
        vector<TreeNode*> myNodes;
        TreeNode *p;
        vector<int> element;
        vector<int> temp;
        
       
        if (root == NULL)
            return true;
        
        myNodes.push_back(root->left);
        myNodes.push_back(root->right);
        
        while (!myNodes.empty()) {
            int k = myNodes.size();
            //Check NULL nodes
            for (int i = 0; i < k; i++)
                if(myNodes[i] == NULL && myNodes[k - i - 1] != NULL)
                    return false;
            for (int i  = 0; i < k; i++) {
                if (myNodes[0] != NULL) {
                    element.push_back(myNodes[0]->val);
                    myNodes.push_back(myNodes[0]->left);
                    myNodes.push_back(myNodes[0]->right);
                }
                myNodes.erase(myNodes.begin());
            }
            if (check(element) == false)
                return false;
            element.clear();
        }
        return true;
    }
    
    bool check(vector<int> & element) {
        vector<int> temp = element;
        if (element.size() == 0)
            return true;
            
        if (element.size() == 1)
            return false;
            
        reverse(temp.begin(), temp.end());
        if (temp == element)
            return true;
        return false;
    }
};