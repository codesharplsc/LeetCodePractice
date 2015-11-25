class Solution {
public:
    int lengthOfLastWord(string s) {
       int i, j;
       if (s.size() == 0)
         return 0;
         
       for (i = s.size()-1; i >= 0; i--) {
            while (!(
                (s[i] >= 'a' && s[i] <= 'z')||
                (s[i] >= 'A' && s[i] <= 'Z'))) {
                i--;
                if (i < 0)
                    return 0;
            }
            for (j = i; j >= 0; j--)
                if ((s[j] >= 'a' && s[j] <= 'z') || (s[j] >= 'A' && s[j] <= 'Z'))
                    continue;
                else
                    break;
            return i-j;
       }
    }
};