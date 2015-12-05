class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> resultSet;
        vector<int> Element;
        
        for (int i = 0; i < n; i++)
            resultSet.push_back(i + 1);
            
        ComputeCombination(result, Element, resultSet, 0, k);
        
        return result;
        
    }
    
    void ComputeCombination(vector<vector<int>> &result, vector<int> Element, vector<int>& resultSet, int resultSetPos, int remain) {
        
        if (remain == 0) {
            result.push_back(Element);
            return;
        }
        if (resultSetPos == resultSet.size())
            return;
        for (int i = resultSetPos; i < resultSet.size(); i++) {
            vector<int> temp = Element; 
            temp.push_back(resultSet[i]);
            ComputeCombination(result, temp, resultSet, i + 1, remain - 1);
        }
        return;
        
    }
};