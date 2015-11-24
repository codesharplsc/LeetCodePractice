class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>> Result;

        map<string,int> OrderList;
        map<string,int> StringPos;
        
        int pos;
        
        sort(strs.begin(),strs.end());
        
        for(int i = 0 ; i< strs.size();i++){
           string tmp = strs[i];
           sort(tmp.begin(),tmp.end());
           
           if(OrderList[tmp] == 0)
                pos=-1;
            else
                pos = StringPos[tmp];
          
           if(pos == -1){
                vector<string> ResultElement;
                ResultElement.push_back(strs[i]);
                Result.push_back(ResultElement);
                OrderList[tmp] = 1;
                StringPos[tmp] = Result.size()-1;
           }else
                Result[pos].push_back(strs[i]);
                
        }
        
        return Result;
        
    }
    
    
    
  
};