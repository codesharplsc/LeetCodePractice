class Solution {
public:
    int numDecodings(string s) {
        int Number[s.size()];
        if (s.size() == 0)
            return 0;
        Number[0] = (s[0] == '0')?0:1;
        if(s.size() == 1)
            return Number[0];
            
        if(s[1]=='0' && s[0] <=' 2'&& s[0] != '0')
            Number[1] = Number[0];
        else if(s[1] =='0')
            Number[1] = 0;
            else if (s[0] > '2' || (s[0] =='2' && s[1] > '6') || s[0] == '0')
                Number[1] = Number[0];
            else
                Number[1] = 2;
            
        for (int i = 2; i < s.size(); i++)
            if (s[i] == '0' && s[i-1] <= '2' && s[i-1] != '0')
                Number[i] = Number[i - 2];
            else if (s[i] =='0')
                Number[i] = 0;
                else if (s[i-1] > '2' || (s[i - 1] == '2' && s[i] > '6') || s[i-1] == '0')
                        Number[i] = Number[i - 1];
                    else 
                    Number[i] = Number[i - 1] + Number[i - 2];
            
            
        return Number[s.size() - 1];  
    }
   
};