class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        map<vector<int>,int> IsDuplicate;
        vector<int> PreResult;
        
        sort(candidates.begin(),candidates.end());
        combinationSum(candidates,target,result,0,PreResult,IsDuplicate);
        
        return result;
    }
    
    void combinationSum(vector<int> &candidates, int target, vector<vector<int>> &result,int start,vector<int> PreResult,
                        map<vector<int>, int> &IsDuplicate){
        if(target == 0){
            sort(PreResult.begin(),PreResult.end());
            if(IsDuplicate[PreResult] == 0){
                IsDuplicate[PreResult] = 1;
                result.push_back(PreResult);
                
                return;
            }else
                return;
        }
        
        if(target <0)
            return;
            
       
        for(int i = start; i <candidates.size();i++){
            vector<int> PrePreResult = PreResult;
            PrePreResult.push_back(candidates[i]);
            if(target-candidates[i]<0)
                return;
            combinationSum(candidates,target-candidates[i],result,i+1,PrePreResult,IsDuplicate);
        }
        
        return;
    }
};