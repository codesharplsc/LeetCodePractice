//So the loop is numRows times. Each character is adding from a step of numRow*2-2 however, the numRow*2-2 has something between each two number

class Solution {
public:
    string convert(string s, int numRows) {
        
        if(numRows == 1)
            return s;
            
        int Step = numRows*2 - 2;
        string result = "";
        
        for(int i = 0 ; i < numRows;i++){
            int Start = i;
            
            if(i == 0){
                while(Start<s.size())
                {   result += s[Start];
                    Start += Step;
                }
                
            }else{
                int FrontPart = Step-i*2;
                while(Start<s.size())
                {
                    result +=s[Start];
                    if(Start+FrontPart<s.size()&& FrontPart!=0)
                        result +=s[Start+FrontPart];
                    Start+=Step;
                }
                
            }
            
            
        }
         return result;
    }
    
};