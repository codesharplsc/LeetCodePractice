class Solution {
public:
    bool isMatch(string s, string p) {
        int p1 = 0,p2 = 0;
        
        return isMatchRecursive(s, p1,p,p2);
    }
    
    bool isMatchRecursive(string &s, int p1, string &p ,int p2){
        int len1 = s.size(), len2 = p.size();
        int i;
        
        while(p1<len1&& p2<len2-1){
            
            if(p[p2]=='.' && p[p2+1]!='*'){
                p1++;
                p2++;
                
            }else if (p[p2] == '.' &&p[p2+1] =='*'){
                for(int j = p1; j<len1; j++)
                    if(isMatchRecursive(s,j+1,p,p2+2) == true)
                        return true;
                p2 = p2+2;
                
            }else if(p[p2] != '.' && p[p2+1]=='*'){
                for(int j = p1;s[j]==p[p2]&&j<len1;j++)
                    if(isMatchRecursive(s,j+1,p,p2+2) == true)
                        return true;
                p2 = p2+2;
                
            }else{
                //p[p2] != '.' &&p[p2+1] !='.'
                if(s[p1]!=p[p2])
                    return false;
                p1++;
                p2++;
            }
        }
        //p1 reaches the end however p2 doesn't reach the end
        if(p1==len1&&p2 == len2)
            return true;
        
        if(p1==len1&&p2 == len2-1)
            return false;
        
        if(p1 == len1 && p2 <len2-1){
            for(i = p2+1; i <len2;i = i+2){
                if(p[i] != '*')
                    return false;
            }
            if(i!=len2+1)
                return false;
            
            return true;
        }
        
        //p2 reaches the end while p1 doesn't
        if(p1!= len1 && p2 == len2)
            return false;
        
        
        if(p1!= len1 && p2 == len2-1){
            if(p1 == len1-1){
                if(s[p1] == p[p2] || p[p2] =='.')
                    return true;
                else
                    return false;
            }else
                return false;
            
        }
        //never reached
        cout<<"XXX";
        return true;
    }
    
};
