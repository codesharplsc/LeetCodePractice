class Solution {
public:
    int myAtoi(string str) {
        double result = 0;
        //storing the operator's position
        int flagPos = -1;
        int flagNag = -1;
        int j = 0;
       for( j = 0;j<str.size();j++){
            if(str[j] =='+')
               {flagPos  = j;break;}
            if(str[j] =='-')
                {flagNag = j;break;}
           
       }
        j = j+1;
        if(j ==str.size())
            return 0;
        if(flagPos !=-1&&flagNag !=-1)
            return 0;
        if(str[j]<48||str[j]>57)
            return 0;
       
        if(flagNag == -1){
            if(j-flagPos !=1&&flagPos!=-1) return 0;
            
            for(int i = j;i<str.size();i++){
              if(str[i]>=48&&str[i]<=57){
                if(result!=0){
                    result *= 10;
                    result += (str[i]-48);
                    if(TestIfOutBound(result))
                        return OutBound(result);}
                else{
                    result +=str[i]-48;}
              }else{
                  return result;
              }
                    
            }
        }else{
            if(j-flagNag!=1) return 0;
            for(int i = j;i<str.size();i++){
                if(str[i]>=48&&str[i]<=57){
                if(result!=0){
                    result *= 10;
                    result -=(str[i]-48);
                    if(TestIfOutBound(result))
                        return OutBound(result);}
                else{
                    result -=(str[i]-48);}
                }else{
                    return result;}
            }
        
        }
        
        return result;
    }
    
    int OutBound(double x){
        if(x>INT_MAX)
            return INT_MAX;
        if(x<INT_MIN)
            return INT_MIN;
        return 0;
    }
    int TestIfOutBound(double x){
        if(x>INT_MAX||x<INT_MIN)
            return 1;
        return 0;
    }
};