/*
Using IsPalindrome[i][j] array to store the result of string starting from i to j. If it is 0 then it means s.substr(i,j-i+1) is not a Palindrome,
Otherwise it is. The total time takes O(n2).

*/



int IsPalindrome[1000][1000];
class Solution {
public:
    int max_length;
    int SubStringStart;
    
    string longestPalindrome(string s){
        
        memset(IsPalindrome,0,sizeof(IsPalindrome));
        memset(MiddleValue,0,sizeof(MiddleValue));
        
        if(s.size() == 1)
            return s;
        if(s.size() == 2)
            return s[0]==s[1]?s:s[0];       


        for(int k = 0;k <s.size();k++)
            IsPalindrome[k][k] = 1;
        
        for(int k = 0;k < s.size()-1;k++){
            if(s[k] == s[k+1])
                IsPalindrome[k][k+1] = 2;
            else
                IsPalindrome[k][k+1] = 0;
        }

        max_length = 2;

        for(int step = 2;step<s.size();step++){
            for（int StartPos = 0 ;StartPos < s.size();StartPos++){
                int EndPos = StartPos+step;
                
                if(IsPalindrome[StartPos+1][EndPos-1] !=0&&s[StartPos] ==s[EndPos]){
                    IsPalindrome[StartPos][EndPos] = IsPalindrome[StartPos+1][EndPos-1] +2;
                    max_length = IsPalindrome[StartPos][EndPos];
                    SubStringStart = StartPos;
                }
                
                else
                    IsPalindrome[StartPos][EndPos] = 0;

            }


        }

        return s.substr(SubStringStart,StartPos);
    }
};

  



