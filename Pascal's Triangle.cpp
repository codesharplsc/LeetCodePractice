class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<int> myElement;
        vector<vector<int>> result;
        result.push_back({1});
        if (numRows == 0)
            return {};
        
        for ( int i = 1; i < numRows; i++) {
            myElement.clear();
            for (int j = 0; j < result[i - 1].size() - 1; j++)
                myElement.push_back(result[i - 1][j] + result[i - 1][j + 1]);
            myElement.push_back(1);
            myElement.insert(myElement.begin(), 1);
            
            result.push_back(myElement);
        }
        
        return result;
    }
};