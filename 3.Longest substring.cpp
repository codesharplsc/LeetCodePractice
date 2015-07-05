/*
At first, I was thinking using recursive function to achieve the goal. With each 
substring's length starting from 1, 2,4,8...and check newly added element to be a 
repeated one. This will takes O(logn) to divde the step, and O(1) to compare and O(n)
to build the map table. Total takes O(n*logn),this definitely takes too much time.

Another approach providing below takes O(n) which just use two pointer i, j to point to the
start of the substring and the end of the substring. A map is used to store the occurences of 
each string characteristic and another map is used to store its last occured position.

*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
     
        
        if(s.size() == 0) return 0;
        if(s.size() == 1) return 1;
        map<char,int> mymap;
        map<char,int> mymap_pos;
        int result = 1;
        int i  = 0,j = 1;
        mymap[s[0]] =1;
        mymap_pos[s[0]] = 0;
        
        while(j<s.size()){
            //This character has not been added
            if(mymap[s[j]]==0){
                mymap[s[j]]++;
                mymap_pos[s[j]] = j;
                j++;
                if(j==s.size()&&(j-i)>result)
                    result = j-i;
            }
            else{
                //renew the max length
                if((j-i)>result)
                    result = j-i;
                //remove all the occurence between i and j
                for(int k = i;k<=mymap_pos[s[j]];k++)
                    mymap[s[k]]--;
                i = mymap_pos[s[j]]+1;
            }
        }
        
        return result;
    }
    
};