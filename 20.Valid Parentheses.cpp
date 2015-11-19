class Solution {
public:
    bool isValid(string s) {
        vector<char> p;
        vector<char>::iterator iter;
        
        for(int i = 0; i <s.size(); i++){
                
            if(s[i] ==')'){
                //in case there is no element in the vector<char>, so iter=p.end()-1 will not fail
                if(p.empty()) return false;
                iter = p.end()-1;
                while(*iter!='(' && *iter!='{' && * iter!='}' && * iter!='[' && *iter!=']' &&!p.empty())
                    iter = p.erase(p.end()-1);
                
                if(*iter =='(')
                    p.erase(iter);
                else
                    return false;
                    
            }else if(s[i] =='}'){
                if(p.empty()) return false;
                iter = p.end()-1;
                while(*iter!='{' && *iter!='(' && * iter!=')' && *iter!='[' && * iter!=']' && !p.empty())
                    iter = p.erase(p.end()-1);
                
                if(*iter =='{')
                    p.erase(iter);
                else
                    return false;
                    
            }else if(s[i] ==']'){
                if(p.empty()) return false;
                    iter = p.end()-1;
                while(*iter!='[' && *iter!='(' && * iter!=')' && *iter!='{' && * iter!='}' && !p.empty())
                    iter = p.erase(p.end()-1);
                
                if(*iter =='[')
                    p.erase(iter);
                else
                    return false;
            }else
                p.push_back(s[i]);
            
        }
        for(int i = 0; i <p.size();i++)
            if(s[i] == '[' || s[i] ==']' || s[i] =='{' || s[i] =='}' || s[i] =='(' || s[i] ==')')
                return false;
                
        return true;
        
    }
};