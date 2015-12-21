class Solution {
public:
 /*
 change value passing to reference
 map<pair<int,int>,int> visited -> map<pair<int,int>,int> &visited
        .........               -> ADD: visited[make_pair(i,j)] = 0
 */
 bool Compute(vector<vector<char>> &board,int i, int j,string &word,int len,map<pair<int,int>,int> &visited){
        visited[make_pair(i,j)] = 1;
        if (len == 0)
            return true;
        if (board[i][j] == word[word.size()-len]) {
            //check the len value before i or j, because the i may equal to j equal to 0
            if(len-1 == 0)
                return true;
            
            if(i-1>=0 && visited[make_pair(i-1,j)] == 0 && board[i-1][j] == word[word.size()-len+1] &&Compute(board,i-1,j,word,len-1,visited) == true)
                return true;
            
            if(i+1<board.size() && visited[make_pair(i+1,j)] == 0 &&board[i+1][j] == word[word.size()-len+1] &&Compute(board,i+1,j,word,len-1,visited) == true)
                return true;
            
            if(j-1>=0 && visited[make_pair(i,j-1)] == 0 &&board[i][j-1] == word[word.size()-len+1] &&Compute(board,i,j-1,word,len-1,visited) == true)
                return true;
            
            if(j+1<board[0].size() &&visited[make_pair(i,j+1)] == 0 &&board[i][j+1] == word[word.size()-len+1] && Compute(board,i,j+1,word,len-1,visited) == true)
                return true; 
        }
        
        visited[make_pair(i,j)] = 0;    
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        if(board.size() == 0)
            return false;
        
        map<pair<int,int>,int> visited;
        
        for (int i = 0 ;i < board.size(); i++)
            for(int j = 0; j < board[0].size(); j++){
                visited.clear();
                if (Compute(board, i, j, word, word.size(), visited) == true)
                    return true;
            }
        return false;
    }
};