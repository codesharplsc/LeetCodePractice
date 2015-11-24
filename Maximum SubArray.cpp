// Maintain the localmax(including the new element) and the globalMax to determine the next element
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int LocalMax[nums.size()];
        int GlobalMax[nums.size()];
        LocalMax[0] = nums[0];
        GlobalMax[0] = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            if (LocalMax[i-1] < 0)
                LocalMax[i] = nums[i];
            else
                LocalMax[i] = LocalMax[i-1]+nums[i];
            
            GlobalMax[i] = GlobalMax[i-1] > LocalMax[i]?GlobalMax[i-1] : LocalMax[i];
        }
        return GlobalMax[nums.size()-1];       
    }
};