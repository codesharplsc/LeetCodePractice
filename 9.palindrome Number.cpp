class Solution {
public:
    bool isPalindrome(int x) {
        long div = 1;
        if( x < 0)
            return false;
        if(x == 0)
            return true;
            
        while(x/div != 0){
            div = div*10;
        }
        div = div/10;
        
        
        int left,right;
        
        while(div !=0){
            left = x/div;
            right = x%10;
            
            if(left!=right)
                return false;
            
            x = (x-left*div)/10;
            div = div/100;
        }
        
        return true;
        
    }
};