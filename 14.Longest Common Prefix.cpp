class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        if(strs.size() == 0)
            return "";
        if(strs.size() == 1)
            return strs[0];
            
        int result = 0;
        int MinLength = strs[0].size();
        
       
        for(int i = 1;i<strs.size();i++)
            if(strs[i].size()<MinLength)
                MinLength = strs[i].size();
    
        for(int i =  0;i<MinLength;i++){
            for(int j = 0;j<strs.size()-1;j++)
                if(strs[j][i]!=strs[j+1][i])
                    return strs[0].substr(0,result);
            result = i+1;
        }
        
        return strs[0].substr(0,result);
        
    }
};