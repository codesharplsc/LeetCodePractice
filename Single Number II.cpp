class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int result = 0;
        vector<int> Num(32,0);
        
        for(int i = 0; i<nums.size();i++){
            for(int j =0;j<32;j++)
                //spent so much time here because "&"" is executed prior than "+"
                Num[j] = ( ((nums[i]>>j)&1) + (Num[j]) )%3;
            
        }
        
        for(int i = 0;i<32;i++)
            result+=Num[i]<<i;
        
        return result;
        
    }
};