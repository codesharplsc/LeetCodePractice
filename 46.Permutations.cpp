class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> result;
        vector<int> PreResult;
        vector<int> indicator;
        
        for(int i = 0 ;i<nums.size();i++)
            indicator.push_back(0);
            
        ComputePermute(result,nums,nums.size(),indicator,PreResult);
        return result;
        
        
    }
    
    void ComputePermute(vector<vector<int>> &result, vector<int> &nums, int remain,vector<int> indicator, 
                        vector<int> PreResult){
        if(remain == 0){
            result.push_back(PreResult);
            return;
        }
        
        
        for(int i = 0; i<nums.size();i++){
            if(indicator[i]==0){
                vector<int> tempindicator= indicator;
                vector<int> tempPreResult = PreResult;
                
                tempindicator[i] = 1;
                tempPreResult.push_back(nums[i]);
                ComputePermute(result,nums,remain-1, tempindicator,tempPreResult);
            }
            
        }
            
        
    }
    
};