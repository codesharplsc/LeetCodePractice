class Solution {
public:
    int numTrees(int n) {
        int numTree[n+1];
        int temp;
        numTree[0] = 0;
        numTree[1] = 1;
        numTree[2] = 2;
        numTree[3] = 5;
        for (int i = 4; i <= n;i++) {
            numTree[i] = 0;
            
            for (int j = 0; j <= i - 1; j++) {
                if (j==0 || j == i-1)
                    numTree[i] += numTree[i - 1];
                else
                    numTree[i] += (numTree[j]) * (numTree[i - 1 - j]);
            }   
        }
        return numTree[n];
    }
};