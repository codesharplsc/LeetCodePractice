//Add by digits
class Solution {
public:
    string addBinary(string a, string b) {
        int p1 = a.size()-1;
        int p2 = b.size()-1;
        int Flag = 0;
        string result = "";
        
        while (p1 >= 0 & &p 2>= 0) {
            int temp = a[p1] - 48 + b[p2] - 48 + Flag;
            if (temp > 1) {
                temp = temp-2;
                Flag = 1;
            }
            else
                Flag = 0;
                
            result += to_string(temp);
            p1--;
            p2--;
        }
        
        while (p1 >= 0) {
            int temp = a[p1] - 48 + Flag;
            if (temp > 1) {
                temp = 0;
                Flag = 1;
            }
            else
                Flag = 0;
            result += to_string(temp);
            p1--;
        }
        
        while (p2 >= 0) {
            int temp = b[p2] - 48 + Flag;
            if (temp > 1) {
                temp = 0;
                Flag = 1;
            }
            else
                Flag = 0;
            result += to_string(temp);
            p2--;
        }
        
        if (Flag == 1)
            result += to_string(Flag);
        reverse(result.begin(),result.end());
        return result;
    }
};