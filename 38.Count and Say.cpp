class Solution {
public:
    string countAndSay(int n) {
        string result = "1";
        if(n == 0)
            return "";
        for(int i = 1;i<n;i++)
            result = returnNextString(result);
        
        return result;
    }
    
    string returnNextString(string s){
        int i = 0,j,num;
        string Cnumber;
        string result = "";
        
        for(i = 0; i<s.size(); i=j+1){
            num = 1;
            Cnumber = s[i];
            for(j = i;j+1<s.size()&&s[j]==s[j+1];j++)
                num++;
                
            result += std::to_string(num)+Cnumber;
        }
        
        return result;
    }
    
};