/*
Using recursive function came into my mind. However, the intermediate result should be stored otherwise it will be an O(n!) time complexity
*/

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        if (triangle.size() == 0)
            return 0;
        if (triangle.size() == 1)
            return triangle[0][0];
            
        vector<vector<int>> MinArray = triangle;
        
        for(int i = 0;i<MinArray.size();i++)
            for(int j = 0 ;j<MinArray[i].size();j++)
                MinArray[i][j] = 0;
                
        return ComputeSubTriangle(triangle, 1, 0, MinArray) + triangle[0][0];
    }
    
    
    int ComputeSubTriangle(vector<vector<int>> &triangle, int RowNum, int PrevPos, vector<vector<int>> &MinArray) {
        int result1, result2, result3, result;
        //reach the end of the element
        if (RowNum == triangle.size())
            return 0;
        
        if (MinArray[RowNum][PrevPos] != 0)
            return MinArray[RowNum][PrevPos];
        
        result1 = ComputeSubTriangle(triangle, RowNum + 1, PrevPos, MinArray) + triangle[RowNum][PrevPos];
        result2 = ComputeSubTriangle(triangle, RowNum + 1, PrevPos + 1, MinArray) + triangle[RowNum][PrevPos + 1];
          
        result = result1>result2?result2:result1;
        MinArray[RowNum][PrevPos] = result;
            
        return result;
    }
};