//For each step, select the minimum way between top-down or left-down

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        
        if (grid.size() == 0)
            return 0;
        vector<vector<int>> MyGraph = grid;
        
        MyGraph[0][0] = grid[0][0];
        for (int i = 1; i < grid.size(); i++)
            MyGraph[i][0] = grid[i][0] + MyGraph[i-1][0];
        for (int i = 1; i<grid[0].size();i++)
            MyGraph[0][i] = grid[0][i] + MyGraph[0][i-1];
        
        for (int i = 1 ; i < grid.size(); i++)
            for(int j = 1;j < grid[0].size(); j++){
                int left = MyGraph[i][j-1];
                int top = MyGraph[i-1][j];
                MyGraph[i][j] = left > top?top:left;
                MyGraph[i][j] += grid[i][j];
                
            }
            
        return MyGraph[grid.size()-1][grid[0].size()-1];
    }
};