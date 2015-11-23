class Solution {
public:
    string multiply(string num1, string num2) {
        int len1 = num1.size();
        int len2 = num2.size();
        int p1 = len1-1,p2 = len2-1,OverTen = 0;
        int DigitResult;
        string result = "";
        string multiplyresult = "";
        
        if(len1 == 0 || len2 == 0)
            return "";
        if(num2 == "0" || num1 == "0")
            return "0";
        
        for(;p2>=0;p2--){
            OverTen = 0;
            
            p1 = len1-1;
            multiplyresult = "";
            while(p1>=0){
                DigitResult = (int)(num2[p2]-48)*(int)(num1[p1]-48)+OverTen;
                multiplyresult+=to_string(DigitResult%10);
                
                OverTen = DigitResult/10;
                p1--;
            }
            
            if(OverTen!=0)
                multiplyresult+=to_string(OverTen);
            reverse(multiplyresult.begin(),multiplyresult.end());
            //apply the "0"
            for(int k = p2; k<len2-1;k++)
                multiplyresult+="0";
            
            result = AddTwoString(result,multiplyresult);
        }
        
        return result;
    }
    
    string AddTwoString(string result,string multiplyresult){
        if(result == "")
            return multiplyresult;
        int len1 =result.size();
        int len2 = multiplyresult.size();
        int p1 = len1-1, p2 = len2-1;
        int OverTen = 0, DigitResult = 0;
        string Addresult = "";
        
        while(p1>=0 &&p2>=0){
            DigitResult = (int)(multiplyresult[p2]-48)+(int)(result[p1]-48)+OverTen;
            Addresult+=to_string(DigitResult%10);
            OverTen = DigitResult/10;
            p1--;
            p2--;
        }
        if(p1!=-1)
            while(p1>=0){
                DigitResult = (int)(result[p1]-48)+OverTen;
                Addresult+=to_string(DigitResult%10);
                OverTen = DigitResult/10;
                p1--;
            }
        
        if(p2!=-1)
            while(p2>=0){
                DigitResult = (int)(multiplyresult[p2]-48)+OverTen;
                Addresult+=to_string(DigitResult%10);
                OverTen = DigitResult/10;
                p2--;
            }
        
        if(OverTen != 0 )
            Addresult+=to_string(OverTen);
        
        reverse(Addresult.begin(),Addresult.end());
        
        return Addresult;
        
    }
    
};