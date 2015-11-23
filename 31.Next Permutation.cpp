//Scan from right, to find the first element that is non-increasing
//Scan again, get the second element that is greater than the first element
//Swap, sort the element from the first element to the end
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int left = 0,i,temp;
        
        if(nums.size()<=1)
            return;
        
        for(i = nums.size()-2;i>=0;i--)
            if(nums[i]<nums[i+1])
                break;
        //Here is the trick that I need to check if it is the greatest element here!!!      
        if(i==-1){
            sort(nums.begin(),nums.end());
            return;
        }
        left =i;    
        
        for(i = nums.size()-1;i>left;i--){
            if(nums[i]>nums[left]){
                temp = nums[i];
                nums[i] = nums[left];
                nums[left] = temp;
                sort(nums.begin()+left+1,nums.end());
                return;
            }
        }
        
        
        return;
    }
};