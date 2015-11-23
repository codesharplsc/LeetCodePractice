//Binary search find the target, then applying  bidirectional binary search on both side. This bidirectional binary search needs some modification
//on original binary search because the end condition is not finding the  element,but go over all the element in the subvector

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int startPos = 0, endPos = nums.size()-1;
        int startResult, endResult;
        vector<int> result;
        
        int midPos = (startPos+endPos)/2;
        
        if(nums[startPos] >target || nums[endPos]< target)
            return {-1,-1};
            
        while(startPos<=endPos){
            if(nums[midPos]== target){
                startResult = searchSingleLeft(nums,startPos,midPos,target);
                endResult   = searchSingleRight(nums,midPos,endPos,target);
                result.push_back(startResult);
                result.push_back(endResult);
                return result;
            }else if(nums[midPos]<target){
                    startPos = midPos+1;
                    midPos = (startPos+endPos)/2;
                    }else if(nums[midPos]>target){
                        endPos = midPos-1;
                        midPos  = (startPos+endPos)/2;
                    }
            
        }
        
        return {-1,-1};
        
    }
    //find the leftmost element
    int searchSingleLeft(vector<int>& nums, int start,int end,int target){
        int mid = (start+end)/2;
        int result= end;
        
        while(start<end){
            if(nums[mid] == target){
                result = mid;
                end = mid;
            }else
                start = mid+1;
            
            mid = (start+end)/2;
        }
        
        return result;
    }
    //find the rightmost element
    int searchSingleRight(vector<int>& nums, int start,int end, int target){
        int mid = (start+end)/2;
        int result = start;
        
        while(start<=end){
            if(nums[mid] == target){
                result = mid;
                start = mid+1;
            }else
                end = mid-1;
            
            mid = (start+end)/2;
        }
        
        return result;
    }
    
};