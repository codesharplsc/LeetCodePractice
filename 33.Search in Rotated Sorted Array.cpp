//Find the subvector that is sorted than applying binary search on it

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0, end = nums.size()-1;
        int mid = (start+end)/2;
        int returnIndex = 0;
        
     
        
        while(start<=end){
            if(nums[mid]>nums[start]){
                returnIndex = sortsearch(nums,start,mid,target);
                if(returnIndex !=-1)
                    return returnIndex;
                
                start = mid+1;
            }else if(nums[mid] <nums[start]){
                    returnIndex = sortsearch(nums,mid,end,target);
                    if(returnIndex !=-1)
                        return returnIndex;
                    end = mid-1;
                 //nums[mid] == nums[start]
                 }else{
                     if(nums[mid] == target)
                         return mid;
                     if(nums[end] == target)
                         return end;
                     break;
                 }
            mid = (start+end)/2;
        }
        
        return -1;
    }
    
    
    //Search in a sorted vector
    int sortsearch(vector<int> &nums, int start,int end,int target){
        int mid = (start+end)/2;
        while(start<=end){
            if(target == nums[mid])
                return mid;
            else if(target <nums[mid])
                end = mid-1;
            else
                start = mid+1;
            mid = (start+end)/2;
        }
        
        return -1;
        
    }
    
    
};
