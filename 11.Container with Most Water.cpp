//Two pointer question. For a given container, find the lower bound, then move it to the greater bound to see if it generates a bigger container.

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxStart = 0, StartPos = maxStart;
        int maxEnd = height.size()-1, EndPos = maxEnd;
        
        int MaxArea = height[maxStart]>height[maxEnd]?(maxEnd-maxStart)*height[maxEnd]:(maxEnd-maxStart)*height[maxStart];
        int NewArea = 0;
        
        while(StartPos<EndPos){
            if(height[StartPos]>height[maxStart] || height[EndPos]  >height[maxEnd]){
                NewArea = height[StartPos]>height[EndPos]?(EndPos-StartPos)*height[EndPos]:(EndPos-StartPos)*height[StartPos];
                if(NewArea > MaxArea){
                    MaxArea = NewArea;
                    maxStart = StartPos;
                    maxEnd = EndPos;
                }
                
            }
             //height[StartPos] <=height[maxStart] && height[EndPos]<height[maxEnd]
            if(height[StartPos] >height[EndPos])
                    EndPos--;
                else
                    StartPos++;
        
            
        }
        
        return MaxArea;
    }
};