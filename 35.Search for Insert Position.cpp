class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.size() == 0)
            return 0;
        int start = 0, end = nums.size()-1;
        int mid = (start+end)/2;
        while(start<=end){
            if(nums[mid] == target)
                return mid;
            
            if(nums[mid]>target)
                end = mid-1;
            else
                start = mid+1;
            
            mid = (start+end)/2;
            
        }
        return start;
    }
};