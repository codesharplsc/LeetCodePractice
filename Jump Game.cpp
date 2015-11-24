class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len = nums.size();
        int MaxJump[len];
        int temp1;
        int temp2;
       
        if (len == 1)
            return true;
        MaxJump[0] = nums[0];
            
        for (int i = 1; i < len; i++) {
            if (MaxJump[i-1] >= i) {
                temp1 = i+nums[i];
                temp2 = MaxJump[i-1];
                MaxJump[i] = temp1 > temp2?temp1:temp2;     
            }
            else
                MaxJump[i] = MaxJump[i-1];
        }
        if (MaxJump[len-1] >= len-1)
            return true;
        return false;
    }
};