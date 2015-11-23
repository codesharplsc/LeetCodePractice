//Place the positive element in begining subvector. Care for if the exchange is between two element, simply break the loop

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i, newPos,temp;
 
        
        if(nums.size() == 0)
            return 1;
        
        int pos;
        
        for(i = 0 ; i<nums.size(); i++){
            if(nums[i]<=0)
                continue;
            else{
                
               
                
               
                while(nums[i]!=i+1&&nums[i]<=nums.size()){
                    newPos = nums[i]-1;
                    //This is used for exchanging same element e.g. nums[15] = 3, nums[2] = 3!!!!!!
                    if(nums[newPos] == nums[i])
                        break;
                    temp = nums[i];
                    nums[i] = nums[newPos];
                    nums[newPos] = temp;
               
                   
          
                }
                
                
            }
            
        }
        
        for(i = 0 ; i<nums.size();i++)
            if(i+1!=nums[i])
                return i+1;
        
        //the nums now is continuously
        return i+1;
    }
    
};