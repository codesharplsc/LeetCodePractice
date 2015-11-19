class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        map<vector<int>, int> TestDuplicate;
        int target1;
        int target2;
        
        for(int i = 0; i< nums.size(); i++){
            target1 = target-nums[i];
            for(int j = i+1; j<nums.size(); j++){
                target2 = target1 - nums[j];
                int start = j+1;
                int end = nums.size()-1;
                while(start<end){
                    if(target2 == nums[start]+nums[end]){
                       vector<int> PreResult;
                       PreResult.push_back(nums[i]);
                       PreResult.push_back(nums[j]);
                       PreResult.push_back(nums[start]);
                       PreResult.push_back(nums[end]);
                       
                       if(TestDuplicate[PreResult] ==0){
                            result.push_back(PreResult);
                            TestDuplicate[PreResult] = 1;
                       }
                       start++;
                       end--;
            
                    }else if(target2<nums[start]+nums[end]){
                        end--;    
                    }else
                        start++;
                }
            }
        }
        
        return result;
        
    }
};