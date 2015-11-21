class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = 0,i = 0,j = 0;
      
        for(i = 0; i <nums.size();){
                
                nums[len] = nums[i];
                len++;
                for(j = i+1; j<nums.size()&&nums[j]==nums[i];j++);
                i = j;
                

        }
        
        
        return len;
        
    }
};