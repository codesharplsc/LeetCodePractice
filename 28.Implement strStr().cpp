class Solution {
public:
    int strStr(string haystack, string needle) {
        return haystack.find(needle);
        /*
        int i=0,j=0;
       
        
        if(haystack.size() == 0 && needle.size() == 0)
            return 0;
        if(needle.size() == 0)
            return 0;
        
        vector<int> next = ReturnNextArray(needle);
        while(i<haystack.size()){
            if(j == -1 || haystack[i] == needle[j]){
                i++;j++;
                if(j == needle.size())
                    return i-needle.size();
            }else
                j = next[j];
        }
        
        return -1;
        */
        
        
    }
    
    vector<int> ReturnNextArray(string needle){
        int i = 0, j =-1;
        int PreResult[needle.size()];
        PreResult[0] =-1;
        
        while(i<needle.size()){
            if(j == -1 || needle[i] == needle[j]){
                i++;
                j++;
                //This is in case the array out of bound
                if(i == needle.size())
                    break;
                PreResult[i] = j;
            }else
                j = PreResult[j];
        }
        
        vector<int> result;
        for(int k = 0; k<needle.size();k++)
            result.push_back(PreResult[k]);
        
        return result;
    }
    
};