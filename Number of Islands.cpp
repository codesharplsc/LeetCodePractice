class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int result = 0;
        for (int i = 0 ; i < grid.size(); i++)
            for (int j = 0; j < grid[0].size(); j++)
                if (grid[i][j] == '1') {
                    Mark(grid, i, j);
                    result++;
                }
        
        return result;
        
    }
    
    void Mark(vector<vector<char>>&grid, int row, int col){
        
        int RowLen = grid.size();
        int ColLen = grid[0].size();
        
        grid[row][col] = 'x';
        if (row - 1 >= 0)
            if (grid[row - 1][col] == '1')
                Mark(grid, row - 1, col);
                
        if (col - 1 >= 0)
            if (grid[row][col - 1] == '1')
                Mark(grid,row,col - 1);
        
        if (row + 1 < RowLen)
            if (grid[row + 1][col] == '1')
                Mark(grid,row + 1, col);
                
        if (col + 1 < ColLen)
            if (grid[row][col + 1] == '1')
                Mark(grid, row, col + 1);       
        return;      
    }
    
};