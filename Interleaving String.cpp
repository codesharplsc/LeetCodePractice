class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int p1 = 0,len1 = s1.size();
        int p2 = 0,len2 = s2.size();
        int p3;
        map<vector<int>,int> Mymap;
        vector<int> MymapElement = {0,0,0};
        
        
        vector<vector<int>> TraceRoute;
        
        
        for( p3 = 0; p3<s3.size(); p3++) {
            MymapElement[0] = p1;
            MymapElement[1] = p2;
            MymapElement[2] = p3;
            // the element has been visited
            if (Mymap[MymapElement] == -1) {
                if(TraceRoute.size() == 0)
                    return false;
               
                vector<int> Element;
                Element = TraceRoute[TraceRoute.size() - 1];
                TraceRoute.erase(TraceRoute.end() - 1);
                
                p1 = Element[0];
                p2 = Element[1];
                p3 = Element[2];
               
                continue;
            }
            
            Mymap[MymapElement] = -1;
            
            if (p1 < len1 && p2 < len2 && s3[p3] == s1[p1] && s3[p3] == s2[p2]){
                vector<int> Element;
                Element.push_back(p1);
                Element.push_back(p2 + 1);
                Element.push_back(p3);
                TraceRoute.push_back(Element);
                
                p1++;
                continue;
            }
            
            
            
            if (p1 < len1 && s3[p3] == s1[p1]) {
                p1++;
                continue;
            }
            if (p2 < len2 && s3[p3] == s2[p2]) {
                p2++;
                continue;
                
            }
           
            /*    
            if(p1<len1 && p2<len2 && s3[p3]!=s1[p1] && s3[p3] !=s2[p2]){
             */
            if (TraceRoute.size() == 0)
                return false;
               
            vector<int> Element;
            Element = TraceRoute[TraceRoute.size() - 1];
            TraceRoute.erase(TraceRoute.end() - 1);
                
            p1 = Element[0];
            p2 = Element[1];
            p3 = Element[2];
               
            continue;
            /*}
            */
            
        }
        //the string s1 and s2 happens to end 
        if (p1 == s1.size() && p2 == s2.size() && p3 == s3.size())
            return true;
        
        return false;
    }
};