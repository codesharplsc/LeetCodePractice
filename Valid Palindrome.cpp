class Solution {
public:
    bool isPalindrome(string s) {
        string tmp = s;
        ToLowerCase(tmp);
        
        for(int i = 0; i<tmp.size();){
            if(!((tmp[i]>='a' &&tmp[i]<='z') || (tmp[i]>='0' && tmp[i]<='9') ))
                tmp.erase(tmp.begin()+i);
            else
                i++;
        }
                
        string tmpString =tmp;     
        reverse(tmp.begin(),tmp.end());
        if(tmp == tmpString)
            return true;
        else 
            return false;
    }
    
    void ToLowerCase(string &s){
        
        for (int i = 0; i < s.size(); i++)
            if (s[i] >= 'A' && s[i] <= 'Z')
                s[i] = s[i] + 32;
        return;
    }
};