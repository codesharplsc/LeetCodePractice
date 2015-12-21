class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int p = 0, q = 0, prev;
        while (p < nums.size()) {
            //The prev is for storing the start point of the pointer    
            prev = p;
            while (p + 1 < nums.size() && nums[p] == nums[p + 1])
                p++;
            /*
            if (p - prev >= 2) {
                nums[q] = nums[p];
                q++;
                nums[q] = nums[p];
            }else if (p - prev == 1) {
                nums[q] = nums[p];
                q++;
                nums[q] = nums[p];
            }else
                nums[q] = nums[p];
            //Simplify as
            */
            if (p - prev == 0)
                nums[q] = nums[p];
            else {
                nums[q] = nums[p];
                q++;
                nums[q] = nums[p];
            }


            p++;
            q++;
        }
        return q;
    }
};