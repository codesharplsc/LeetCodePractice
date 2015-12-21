class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1, p2, p3 = 0;
        //Move the element in nums to the end of the nums1. Care for not moving from the order but a reverse-order movement
        for (p1 = m-1 ; p1 >= 0; p1--) 
            nums1[p1+n] = nums1[p1];
        p1 = n;
        if (m == 0) {
            for (p2 = 0 ; p2 < n; p2++)
                nums1[p2] = nums2[p2];
            return;
        }
        
        for (p2 = 0, p3 = 0; p1 < m+n && p2 < n; p3++)
            if (nums1[p1] < nums2[p2]) {
                nums1[p3] = nums1[p1];
                p1++;
            }
            else {
                nums1[p3] = nums2[p2];
                p2++;
            }
            
       
        while (p1 != m+n)
            nums1[p3++] = nums1[p1++];
        while (p2 != n)
            nums1[p3++] = nums2[p2++];
        
        return;
    
        
    }
};