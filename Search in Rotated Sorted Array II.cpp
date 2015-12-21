class Solution {
public:
    bool Binarysearch(vector<int> &nums, int target, int start, int end){
        int mid;
        while (start <= end) { 
            mid = (start + end)/2;
            if (nums[mid] == target)
                return true;
            if (nums[mid] > target)
                end = mid - 1;
            else
                start = mid + 1;     
        }
        return false;
    }
    

    bool searchrange(vector<int>& nums, int start,int end, int target) {
        int mid;
     while (start <= end) {
         mid = (start + end)/2;
         if (nums[mid] == target)
            return true;
         
         if (nums[mid] > nums[start]) {
            if (Binarysearch(nums, target, start, mid - 1) == true)
                return true;
             start = mid + 1;
         }else if(nums[mid] < nums[start]){
            if(Binarysearch(nums, target, mid + 1, end) == true)
                return true;
            end  = mid - 1;
         }else
            return searchrange(nums, start, mid - 1, target) || searchrange(nums, mid + 1, end, target);
            
     }
     return false;
    }
    
    bool search(vector<int>& nums, int target) {
        searchrange(nums, 0, nums.size()-1, target);
        
     }
 
};