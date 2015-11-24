//The rotate image is the 90 degree rotation that rotate a full round of the matrix
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int len  = matrix.size();
      
        if(matrix.size() <= 1)
            return;
       
       rotateOuterBound(matrix,0,0,len);
        return;
        
    }
    
    void rotateOuterBound(vector<vector<int>>& matrix, int row,int col,int len){
        int temp;
        int i;
        if(len == 1 || len ==0)
            return;
        //!!!!!!!
        for(i = 0; i<len-1;i++){
            swap(matrix[row][col+i], matrix[row+i][col+len-1]);
            swap(matrix[row][col+i],matrix[row+len-1][col+len-1-i]);
            swap(matrix[row][col+i],matrix[row+len-1-i][col]);
        }
        rotateOuterBound(matrix,row+1,col+1,len-2);
        
        return;
    }
    
    void swap(int &x, int &y){
        int temp = x;
        x = y;
        y = temp;
        return;
    }
};