class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        
        vector<string> result;
        string element;
        
        ComputeIP(result, element, s, 0, 4);
        
        return result;
    }
    
    void ComputeIP(vector<string> &result, string element, string &s,int StartPos,int PartNum){
        if(PartNum == 0){
            if(StartPos == s.size()){
                element.erase(element.end()-1);
                result.push_back(element);
                return;
            }else
                return;
        }
        
        if (StartPos >= s.size())
            return;
            
        string temp;
        
        if (TestIFValid(s, StartPos, StartPos)) {
            temp = element;
            temp+=s.substr(StartPos,1) + '.';
            
            ComputeIP(result, temp, s, StartPos + 1, PartNum - 1);
        }
        
        if (TestIFValid(s, StartPos, StartPos + 1)) {
            temp = element;
            temp += s.substr(StartPos,2) + '.';
            ComputeIP(result, temp, s, StartPos + 2,PartNum - 1);
        }
        
        if (TestIFValid(s, StartPos, StartPos + 2)) {
            temp = element;
            temp += s.substr(StartPos,3) + '.';
            ComputeIP(result, temp, s, StartPos + 3, PartNum - 1);
        }   
        return;
        
    }
    
    bool TestIFValid(string &s, int StartPos, int EndPos){ 
        int sum = 0;
        
        
        if (EndPos >= s.size())
            return false;
        if (s[StartPos] == '0' && StartPos != EndPos)
            return false;
            
        for (int i = StartPos; i <= EndPos; i++) {
           sum = sum*10;
           sum += s[i] -'0';
            
        }
        
        if (sum >= 0&& sum <= 255)
            return true;
        return false;
    }
};