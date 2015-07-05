class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       vector<int> result;
       map<int, int> map_number;
       //Store in the hash table
       for(int i = 0;i<nums.size();i++)
            map_number[nums[i]] = i;
       
       //Calculate the element and search for its location
       for(int i = 0;i<nums.size();i++){
           int HalfValue = target-nums[i];
           if(map_number[HalfValue]!=0){
                if(map_number[HalfValue]==i)
                    continue;
                result.push_back(i+1);
                result.push_back(map_number[HalfValue]+1);
                break;
            }
              
       }
       return result;
       
        
    }
};