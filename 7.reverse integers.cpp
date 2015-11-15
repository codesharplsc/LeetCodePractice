class Solution {
public:
    int reverse(int x) {
        
        
        
        double result = 0;
        int i = 0;
        while(x!=0){
            int digit = x%10;
            if(result!= 0)
                result *=10;
                
                
            result +=digit;
            x= x/10;
        }
        if(result>2147483647||result<-2147483648)
            return 0;
        
        return (int)result;
        
        
    }
};