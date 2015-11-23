class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        int len = board.size();
        vector<char>TransferRow;
        vector<char> SmallGraph;
        
        int rStart;
        int cStart;
        
        for(int i = 0; i <len;i++){
            //row check
            if(TestDuplicate(board[i],0,len-1) == false)
                return false;
            
            for(int j = 0;j+2<len;j=j+3)
                if(TestDuplicate(board[i],j,j+2) == false)
                    return false;
            
            
            
            
            //check the small box
            SmallGraph.clear();
            rStart = i%3;
            cStart = i/3;
            for(int ii = 0 ;ii<3;ii++)
                for(int jj = 0;jj<3;jj++)
                    SmallGraph.push_back(board[cStart*3+ii][rStart*3+jj]);
            
            if(TestDuplicate(SmallGraph,0,len-1) == false)
                return false;
            
            
            
            //column check
            //transfer the column into rows
            TransferRow.clear();
            for(int k = 0; k <len;k++)
                TransferRow.push_back(board[k][i]);
            
            if(TestDuplicate(TransferRow,0,len-1) == false)
                return false;
            
            for(int m = 0;m+2<len;m=m+3)
                if(TestDuplicate(TransferRow,m, m+2)== false)
                    return false;
        }
        
        
        
        
        
        return true;
    }
    
    bool TestDuplicate(vector<char> myline, int start, int end){
        map<char,int> mymap;
        //every element occurs exactly once
        for(int i = start; i <=end; i++){
            if(mymap[myline[i]] !=0&& myline[i] !='.')
                return false;
            
            mymap[myline[i]] =1;
        }
        
        return true;
    }
    

};