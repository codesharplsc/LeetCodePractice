class Solution {
public:
    vector<int> getRow(int rowIndex) {
       
        vector<int> myElement;
        vector<vector<int>> result;
        result.push_back({1});
        if (rowIndex == 0)
            return result[0];
        
        for (int i = 1; i <= rowIndex; i++) {
            myElement.clear();
            for (int j = 0; j < result[0].size() - 1; j++)
                myElement.push_back(result[0][j] + result[0][j + 1]);
            myElement.push_back(1);
            myElement.insert(myElement.begin(), 1);
            
            result.push_back(myElement);
            result.erase(result.begin());
        }
        
        return result[0];
        
    }
};