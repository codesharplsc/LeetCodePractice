class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> Result;
        vector<int> ResultElement;
    
        //assume no duplicate element in candidates??
        RecursiveSum(candidates,target, 0,Result,ResultElement);
        return Result;
        
    }
    
    void RecursiveSum(vector<int> & candidates, int target, int NewPos, vector<vector<int>> &Result,vector<int> ResultElement){
        if(target == 0){
            sort(ResultElement.begin(),ResultElement.end());
            Result.push_back(ResultElement);
            return;
        }
        
        if(target<0)
            return;
        
        if(NewPos!=candidates.size()){
            
            // the occurence of the element candidates[NewPos] = j times
            for(int j = 0 ;j*candidates[NewPos]<=target;j++){
                if(j != 0)
                    ResultElement.push_back(candidates[NewPos]);
                
                RecursiveSum(candidates,target-j*candidates[NewPos],NewPos+1,Result,ResultElement);
            }
        }
        
        return;
               
            
    }
};