class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        
        if (matrix.size() == 0)
            return result;  
        ComputeMatrix(matrix, result, 0, 0, matrix[0].size(), matrix.size());
        return result;
    }
    void ComputeMatrix(vector<vector<int>> &matrix, vector<int> &result, int row, int col, int lenRow, int lenCol){
        if (lenCol <= 0 || lenRow <= 0)
            return;
        if (lenCol == 1) {
            for (int i = 0; i < lenRow; i++)
                result.push_back(matrix[row][col+i]);
            return;
        }
        
        if (lenRow ==1) {
            for (int i = 0; i < lenCol; i++)
                result.push_back(matrix[row+i][col]);
            return;
        }
        for (int i = 0; i < lenRow; i++ )
            result.push_back(matrix[row][col+i]);
        for (int i = 1; i < lenCol; i++)
            result.push_back(matrix[row+i][col+lenRow-1]);
        for (int i = lenRow-2; i >= 0; i--)
            result.push_back(matrix[row+lenCol-1][col+i]);
        for (int i = lenCol-2; i > 0; i--)
            result.push_back(matrix[row+i][col]);    
        ComputeMatrix(matrix, result, row+1, col+1, lenRow-2, lenCol-2);
        return;
    }
};