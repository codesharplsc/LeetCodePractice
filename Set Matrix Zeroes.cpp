class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.size() == 0)
            return;
        vector<pair<int,int>> zeroElement;
        
        for (int i = 0; i < matrix.size(); i++)
            for(int j = 0; j < matrix[0].size(); j++)
                if (matrix[i][j] == 0)
                    zeroElement.push_back(make_pair(i,j));
                    
        for(int i = 0 ; i < zeroElement.size(); i++)
            SetMatrix(matrix, zeroElement[i].first, zeroElement[i].second,0);
        
        return;
    }
    void SetMatrix(vector<vector<int>> & matrix, int row, int col, int val){
        for (int i = 0; i < matrix[0].size(); i++)
            matrix[row][i] = val;
        for (int j = 0; j < matrix.size(); j++)
            matrix[j][col] = val;
        return;
    }
};