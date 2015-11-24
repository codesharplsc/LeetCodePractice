class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> resultElement;
    
        CalculateNQueen(result, resultElement, n, 0);
        return result;
    }
    void CalculateNQueen(vector<vector<string>> &result, 
    vector<string>resultElement, int n, int PlacedLines) {
        string NewPos;
        vector<string> MyresultElement;
        int i;
        
        if (PlacedLines == n) {
            result.push_back(resultElement);
            return;
        }
        for (i = 0; i < n; i++)
            NewPos+=".";
        for (int i = 0; i< n; i++) {
            if (conflict(resultElement, n, PlacedLines, i) == 0) {
                MyresultElement = resultElement;
                
                NewPos[i] = 'Q';
                MyresultElement.push_back(NewPos);
                CalculateNQueen(result, MyresultElement, n, PlacedLines+1);
            }
            // return it back to normal
            NewPos[i] = '.';
        }
        return;
    }
    // This is the function to check if the placement is invalid
    int conflict(vector<string> &resultElement, int n, int row, int pos) {
        int newRow, newPos;
        if (resultElement.size() == 0)
            return 0;
            
        for (int i = 0; i < resultElement.size(); i++)
            // check the colume
            if (resultElement[i][pos] == 'Q')
                return 1;
        newRow = row;
        newPos = pos;
        while (1) {
            if (newPos == 0 || newRow == 0)
                break;
            if (resultElement[--newRow][--newPos] == 'Q')
                return 1;
        }
        newRow = row;
        newPos = pos;
        while (1) {
            if (newRow == 0 ||newPos == n-1)
                break;
            if (resultElement[--newRow][++newPos] == 'Q')
                return 1;
        }
        return 0;
    }
};