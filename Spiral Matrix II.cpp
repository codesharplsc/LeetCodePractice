class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result;
        vector<int> resultElement;
        
        for (int i = 0 ; i < n; i++)
            resultElement.push_back(0);
        for (int i = 0; i < n ; i++)
            result.push_back(resultElement);
            
        FillMatrix(result, 0, 0, n, 1);
        
        return result;
    }
    
    void FillMatrix(vector<vector<int>> &result, int row, int col, int len, int number){
        if (len <= 0)
            return;
        if (len == 1) {
            result[row][col] = number;
            return;
        }
        
        for (int i = 0; i < len-1; i++)
            result[row][col+i] = number++;
        for (int i = 0; i < len-1; i++)
            result[row+i][col+len-1] = number++;
        
        for (int i = 0; i < len-1; i++)
            result[row+len-1][col+len-1-i] = number++;
        for (int i = 0; i < len-1; i++)
            result[row+len-1-i][col] = number++;
          
        
        FillMatrix(result, row+1, col+1, len-2, number);
        
    }
};