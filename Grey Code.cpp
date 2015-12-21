class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        vector<string> resultstr;
        map<string,int> Mymap;
        
        if (n == 0) {
            result.push_back(0);
            return result;
        }
            
        string startStr = "";
        for (int i = 0; i < n; i++)
            startStr += '0';
        
        resultstr.push_back(startStr);
        Mymap[startStr] = 1;
        
        for (int i = 1; i < (1<<n); i++)
            GenerateStr(resultstr,startStr,Mymap);
        
        for (int i = 0; i < resultstr.size(); i++)
            result.push_back(StrToInt(resultstr[i]));
        return result;
        
    }
    
    void GenerateStr(vector<string>& result,string &str,map<string,int> &IsDuplicate){
        for (int i = str.size() - 1; i >= 0; i--){
            str[i] = (str[i]=='0')?'1':'0';
            if (IsDuplicate[str] == 0) {
                result.push_back(str);
                IsDuplicate[str] = 1;
                return;   
            }else
            str[i] = (str[i]=='0')?'1':'0';
        }
        
        return;
    }
    
    int StrToInt(string str){
        int result = 0;
        
        for (int i = 0;i < str.size(); i++)
            result +=  ( (str[i] == '0')?0:( 1<<( str.size()-1-i ) )  );
        return result;
        
    }
};