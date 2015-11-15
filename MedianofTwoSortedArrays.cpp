/*
I was thinking comparing the median of two array, then remove half element of these two, then compare recursively.
This involves a lot of conditional handling of the odd and even length of the arrays.

*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int nums1_length = nums1.size();
        int nums2_length = nums2.size();
        
        double median1;
        double median2;
        
        int step = 0;
        double result;
        
        int start1 = 0, end1 = nums1.size()-1;
        int start2 = 0, end2 = nums2.size()-1;
        
        if(nums1_length==0&&nums2_length==0)
            return 0;
        if(nums1_length==0)
            return MedianInArray(nums2, start2, end2);
        if(nums2_length==0)
            return MedianInArray(nums1, start1, end1);
        
        
        median1 = MedianInArray(nums1,start1,end1);
        median2 = MedianInArray(nums2,start2,end2);
        
        if(nums1_length<=nums2_length){
            while(start1 != (start1+end1)/2){
                if(median1 == median2)
                    return median1;
                
                if(median1 > median2){
                    if((end1-start1+1)%2==0){
                        start2  = start2+(end1-(start1+end1)/2-1);
                        end1    = (start1+end1)/2+1;
                    
                    }else{
                        start2 = start2+(end1-(start1+end1)/2);
                        end1 = (start1+end1)/2;
                    }
                    
                    
                    median1 = MedianInArray(nums1,start1,end1);
                    median2 = MedianInArray(nums2,start2,end2);
                }else{
                    
                    
                    end2    = end2-((start1+end1)/2-start1);
                    start1  = (start1+end1)/2;
                    median1 = MedianInArray(nums1,start1,end1);
                    median2 = MedianInArray(nums2,start2,end2);
                }
            }
            
            vector<int>nums2_temp(nums2);
            
            //The while loop may end up with two element, so this is to check if the remaining nums1 has 2 elements
            if(end1-start1+1==2)
                InsertToVector(nums1[end1],nums2_temp,start2,end2++);

            
            
            return MedianOneVector(nums1, start1, end1, nums2_temp, start2, end2);
            
            
            
            
            
            
        }else
            return findMedianSortedArrays(nums2, nums1);
        
        
        return 0;
    }
    
    //Return the Median of one element(start1=end1) and one array.
    double MedianOneVector(vector<int>&nums1,int start1,int end1,vector<int> &nums2,int start2,int end2){
        
        
        double result = nums2[(start2 + end2)/2];
        
        if(start2==end2)
            return (double)(result+nums1[start1])/2.0;
        
        
        if((end2-start2+1)%2==0){
            if(result<=nums1[start1]&&nums1[start1]<=nums2[(start2+end2)/2+1])
                return nums1[start1];
            if(result>nums1[start1])
                return result;
            if(nums1[start1]>nums2[(start2+end2)/2+1])
                return nums2[(start2+end2)/2+1];
        }
        else{
            if(nums2[(start2 + end2)/2-1]<nums1[start1]&&nums2[(start2 + end2)/2+1]>nums1[start1])
                return (result+nums1[start1])/2.0;
            if(nums2[(start2 + end2)/2-1]>=nums1[start1])
                return (result+nums2[(start2 + end2)/2-1])/2.0;
            if(nums2[(start2 + end2)/2+1<=nums1[start1]])
                return (result+nums2[(start2+end2)/2+1])/2.0;
            
        }
        //just to avoid none-return value
        return 999;
        
    }
    
    //Insert the elment into the sorted vector nums2
    void InsertToVector(int element,vector<int> &nums2,int start2,int end2){
        
        if(end2==start2){
            if(nums2[start2]>=element)
                {nums2.insert(nums2.begin()+start2,element);return;}
            else
            {nums2.insert(nums2.begin()+start2+1,element);return;}
        }
        
        if(end2-start2 ==1){
            if(nums2[start2]>=element)
                {nums2.insert(nums2.begin()+start2,element);return;}
            
            if(nums2[end2]<=element)
                {nums2.insert(nums2.begin()+end2+1,element);return;}
            else
                {nums2.insert(nums2.begin()+start2+1,element);return;}
        }
        
        int median1 = nums2[(start2+end2)/2];
        int median2 = nums2[(start2+end2)/2+1];
        
        if(element>=median1&&element<=median2)
            {
            nums2.insert(nums2.begin()+(start2+end2)/2+1,element);
            return;
            }
        
        if(element<median1)
            return InsertToVector(element, nums2, start2, (end2+start2)/2);
        if(element>median2)
            return InsertToVector(element, nums2, (end2+start2)/2, end2);
        
        
        
    }
    
    double MedianInArray(vector<int>& nums1,int start, int end) {
        int nums1_length = end-start+1;
        
        if(nums1_length%2 == 0)
            return (nums1[start+nums1_length/2]+nums1[start+nums1_length/2-1])/2.0;
        
        
        else
            return (double)nums1[start+nums1_length/2];
        
    }
};