class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> Element;
        
        sort(nums.begin(), nums.end());
        
        for (int j = 1; j <= nums.size(); j++)
            ComputeSubSet(result, nums, Element, 0, j);
    
        result.push_back({});
        return result;
        
    }
    void ComputeSubSet(vector<vector<int>> &result, vector<int> &nums, vector<int> Element, int StartPos, int SubSetLen){
        if (SubSetLen == 0) {
            result.push_back(Element);
            return;
        }
            
        if (StartPos == nums.size()) {
            return;
        }
            
        for (int i = StartPos;i < nums.size(); i++) {
            vector<int> temp = Element;
            temp.push_back(nums[i]);
            ComputeSubSet(result, nums, temp, i + 1, SubSetLen - 1);
        }
        return;   
    }
};