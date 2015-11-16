class Solution {
public:
    int PositiveNum(int x){
        return x<0?-x:x;
    }

    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int distance = INT_MAX;
        int result = 0;
        
        for(int i = 0; i < nums.size();i++){
            int start = i+1;
            int end   = nums.size()-1;
            while(start<end){
                
                if(PositiveNum(target-nums[i]-nums[start]-nums[end])<distance){
                    distance = PositiveNum(target-nums[i]-nums[start]-nums[end]);
                    result = nums[i]+nums[start]+nums[end];
                    if(target-nums[i]-nums[start]-nums[end]>=distance &&target-nums[i]-nums[start]-nums[end]>=0)
                        start++;
                    else
                        end--;
                }else {
                    if(target-nums[i]-nums[start]-nums[end]>distance)
                        start++;
                    else
                        end--;
                }
            }    
        }
        return result;
    }
};