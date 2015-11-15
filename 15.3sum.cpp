//Another option for two sum is use two pointer in the inner loop
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        map<int,int> Mymap;
        map<int, int>::iterator iter;
        map<int, int>::iterator iter2;
        vector<vector<int>> Result;
        int i = 0;
        
        
        if(nums.size()<3)
            return {};
        
        for(i = 0; i < nums.size();i++)
            Mymap[nums[i]]++;
        //The map's key has been stored in ascending order internally
        for(iter = Mymap.begin(); iter!=Mymap.end();iter++){
            if(iter->second >=2){
                int ThirdElem =0-(iter->first)*2;
                if(Mymap[ThirdElem] !=0 && iter->first<ThirdElem){
                    vector<int> temp;
                    temp.push_back(iter->first);
                    temp.push_back(iter->first);
                    temp.push_back(ThirdElem);
                    Result.push_back(temp);
                }
                
                if(Mymap[ThirdElem] >=3 && iter->first==ThirdElem){
                    vector<int> temp;
                    temp.push_back(iter->first);
                    temp.push_back(iter->first);
                    temp.push_back(ThirdElem);
                    Result.push_back(temp);
                }
            }
            
            //once you have checked map[i], even i may not exist at first, now it is in the map, so you need to check if iter->second !=0 !!
            for(iter2 = iter,iter2++;(iter2!=Mymap.end())&&(iter->second!=0);iter2++){
                int goal = 0-iter->first;
                if(iter2->second!=0){
                    if( (Mymap[goal - iter2->first] != 0&&(goal - iter2->first)>(iter2->first)) ||
                       (Mymap[goal - iter2->first] >= 2&&(goal - iter2->first)==(iter2->first)) ){
                        vector<int> temp;
                        temp.push_back(iter->first);
                        temp.push_back(iter2->first);
                        temp.push_back(goal-iter2->first);
                        Result.push_back(temp);
                        
                    }
                }
            }
            
            
        }
        return Result;
    }
    
};