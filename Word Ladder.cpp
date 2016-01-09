class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        int len = 1;
        string word;
        string s;
        vector<string> MyWordQueue;
        unordered_set<string>::iterator iter;
   
        MyWordQueue.push_back(beginWord);
        
        while (!MyWordQueue.empty()) {
            
            len++;
            int Qlen = MyWordQueue.size();
            for (int k = 0; k < Qlen; k++) {
                word = MyWordQueue[0];
                MyWordQueue.erase(MyWordQueue.begin());
             
                s = word;
                for (int i = 0 ; i < s.size(); i++) {
                    char c = s[i];
                    for (int j = 0 ; j < 26; j++) {
                        if (c == 'a' + j)
                            continue;
                        s[i] = 'a' + j;
                    
                        if (s == endWord)
                            return len;
                        if (wordList.count(s)) {
                            
                            MyWordQueue.push_back(s);
                            wordList.erase(s);
                        }
                    }
                    s[i] = c;
                
                }     
            }
            
        }
        
        return 0;
    }
};