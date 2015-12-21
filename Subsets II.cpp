//Compute from the subsets of n-1 to n
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        map<vector<int>,int> Mymap;
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        
        result.push_back({});
        for (int i = 0; i < nums.size(); i++)
            ComputeSubSets(nums, result, i, Mymap);
        
        return result;
        
    }
    
    void ComputeSubSets(vector<int> &nums, vector<vector<int>> &result,int StartPos,map<vector<int>,int>& Mymap) {
        
        int Number = nums[StartPos];
        vector<int> temp;
        int len = result.size();
        for (int i = 0; i < len; i++) {
            temp = result[i];
            temp.push_back(Number);
            if (Mymap[temp] == 0) {
                result.push_back(temp);
                Mymap[temp] = 1;
            }
            
        }
            
    }
};