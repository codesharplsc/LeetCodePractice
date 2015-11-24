class Solution {
public:
    double myPow(double x, int n) {
     
        
        unsigned PositiveN = n>0?n:-n;
        
        double seed = x;
        double result = 1;
        int count = 0;
        unsigned nn = PositiveN;
      
        unsigned half;
        unsigned Remain=PositiveN;
        
        if(n == 0)
            return 1;
            
        if(PositiveN<2)
            return n>0?x:(1.0/x);
        //Or we can use a array to store the precomputing result of each subresult[2^n] = ...
        while(Remain>1){
            count = 0;
            while((nn = nn/2))
                count++;
            for(int i = 0;i<count;i++)
                seed *=seed;
            
            half = 1<<count;
            Remain = Remain-half;
            result = result*seed;
            seed = x;
            nn = Remain;
        }
        
        if(Remain == 1)
            result = result*x;
        
        return n>0?result:(1.0/result);
    }
};