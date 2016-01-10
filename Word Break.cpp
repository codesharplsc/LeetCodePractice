class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        bool canWordBreak[s.size()];
        memset(canWordBreak, true, s.size());
        
        return CanWordBreak(s, 0, canWordBreak, wordDict);
    }
    
    bool CanWordBreak(string &s, int startPos, bool *canWordBreak, unordered_set<string>& wordDict) {
        string subString;
        if (startPos == s.size())
            return true;
            
        if (canWordBreak[startPos] == false)
            return canWordBreak[startPos];
            
        for (int i = startPos; i < s.size(); i++) {
            subString = s.substr(startPos, i - startPos + 1);
            
            if (wordDict.find(subString) != wordDict.end())
                if (CanWordBreak(s, i + 1, canWordBreak, wordDict))
                    return true;
        }
        canWordBreak[startPos] = false;
        return false;
    }
};