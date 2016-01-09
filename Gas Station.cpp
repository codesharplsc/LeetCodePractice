class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
       
        vector<bool> CanTravel(gas.size(),true);
        
        for (int i = 0; i < gas.size(); i++) {
            if (CanTravel[i] == false)
                continue;
            if (TestIfTravel(0, i, gas, cost, CanTravel, gas.size()))
                return i;
        }
        return -1;
    }
    
    bool TestIfTravel(int gasLeft, int StartPos, vector<int> & gas, vector<int> &cost,vector<bool> &canTravel,int step){
        if (step == 0)
            return true;
        
        canTravel[StartPos] = false;    
        
        if (gas[StartPos] + gasLeft < cost[StartPos])
            return false;
        return TestIfTravel(gasLeft+gas[StartPos] - cost[StartPos],(StartPos + 1) % gas.size(), gas, cost, canTravel, step - 1);
            
    }
};