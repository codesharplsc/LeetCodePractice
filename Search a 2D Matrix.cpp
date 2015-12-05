class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0)
            return false;
    
        int mid,row;
        int rowLen = matrix.size();
        int colLen = matrix[0].size();
        int start = 0,end= rowLen-1;
        
        //search first column
        while (start<=end) {
            mid = (start+end)/2;
            if (matrix[mid][0] == target)
                return true;
            if (matrix[mid][0] > target)
                end = mid-1;
            else
                start = mid+1;
        }
        
        if (matrix[mid][0] > target && mid == 0)
            return false;
        if (matrix[mid][0] > target)
            row = mid-1;
        else
            row = mid;
        
        int start2 = 0,end2 = colLen-1;
        //search rows
        while (start2 <= end2) {
            mid = (start2+end2)/2;
            if (matrix[row][mid] == target)
                return true;
            if (matrix[row][mid] > target)
                end2 = mid - 1;
            else
                start2 = mid + 1;
            
        }
        return false;
        
    }
};