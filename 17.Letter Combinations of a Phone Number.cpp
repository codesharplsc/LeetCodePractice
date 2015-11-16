//Solve two string, then apply the other string at the back

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> mystring = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        int index = 0;
        vector<string> result;
        vector<string> Resultstring;
        
        if(digits.size() == 0)
            return {};
        
           
        for(int k = 0 ; k < mystring[digits[0]-48-2].size();k++)
            result.push_back(mystring[digits[0]-48-2].substr(k,1));
        if(digits.size() == 1)
            return result;
     
        int i=1;
        while(i<digits.size()){
            index = digits[i]-48;
            result = AppendString(result,mystring[index-2]);
            i++;
        }
        
        return result;
    }
    
    vector<string> AppendString(vector<string> v1, string s2){
        vector<string> result;
        for(int k = 0;k<v1.size();k++)
            for(int j = 0;j<s2.size();j++){
                string temp = "";
                temp +=v1[k];
                temp +=s2[j];
                result.push_back(temp);
            }
        return result;
    }
};