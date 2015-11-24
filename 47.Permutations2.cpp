class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        map<vector<int>, int> MyMap;
        vector<int> Element;
        sort(nums.begin(),nums.end());
        ComputePermutation(nums,MyMap,Element,result);
        
        return result;
    }
    
    void ComputePermutation(vector<int> nums,map<vector<int>,int> &MyMap,vector<int>Element,vector<vector<int>>&result){
        
        if(nums.size()==0){
            if(MyMap[Element] == 0){
                result.push_back(Element);
                MyMap[Element] = 1;
                return;
            }
            return;
        }
        vector<int> ElementTemp ;
        vector<int> numsTemp;
        int i = 0;
        while(i<nums.size()){
            ElementTemp=Element;
            ElementTemp.push_back(nums[i]);
            
            numsTemp = nums;
            numsTemp.erase(numsTemp.begin()+i);
            ComputePermutation(numsTemp,MyMap,ElementTemp,result);
            i++;
            while(nums[i-1] ==nums[i])
                i++;
        }       
    }
};