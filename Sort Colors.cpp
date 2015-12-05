/*
Another Soultion lies that use one pointer points to the startpos, and one pointer points to the lastpos, if any element is the biggest, put it to the final
if element is the smallest, put it into the front.
void sortColors(vector<int>& nums) {
    int zero =0, l = 0, r = nums.size()-1;
    while (l <= r) {
        if (nums[l] == 0) 
            swap(nums[l++], nums[zero++]);
        else if (nums[l] == 2) 
            swap(nums[l], nums[r--]);
        else
            l++;
    }
}

*/




class Solution {
public:
    void sortColors(vector<int>& nums) {
        map<int, int> Mymap;
        int len = nums.size();
        for (int i = 0; i < len; i++)
            Mymap[nums[i]]++;
        nums.clear();
        
        
        for (map<int,int>:: iterator iter = Mymap.begin(); iter != Mymap.end(); iter++)
            for (int i = 0 ; i < iter->second; i++)
                nums.push_back(iter->first);
        return;
     
    }
};