class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        if (prices.size() <= 1)
            return 0;
       
        int ProfitByDay[prices.size()];
        //buy and sell in one day
       
        
        ProfitByDay[prices.size() - 1] = 0;
        
        int max = prices[prices.size() - 1];
        int LocalMax;

        for (int i = prices.size() - 2; i >= 0; i--) {
            LocalMax = max - prices[i];
            ProfitByDay[i] = LocalMax > ProfitByDay[i + 1]?LocalMax:ProfitByDay[i + 1];
            if (prices[i] > max)
                max = prices[i];
        }   
        return ProfitByDay[0];
    }
};