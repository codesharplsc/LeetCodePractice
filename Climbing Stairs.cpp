class Solution {
public:
    int climbStairs(int n) {
        if (n == 0)
            return 0;
            
        vector<int> preCompute(n+1,-1);
        return Compute(n, preCompute);
    }
    int Compute(int n, vector<int> &preCompute) {
        int step1, step2;
        if (n < 0)
            return 0;
            
        if (n == 0)
            return 1;
        
        step1 = (preCompute[n-1] == -1)?Compute(n-1, preCompute):preCompute[n-1];
        step2 = (preCompute[n-2] == -1)?Compute(n-2, preCompute):preCompute[n-2];
        preCompute[n] = step1 + step2;
        return preCompute[n]; 
    }
};