class Solution {
public:
    int mySqrt(int x) {
        long long i;
        long long last = 1;
        if(x == 0)
            return 0;
        if (x <= 3)
            return 1;
        //bound check
        for (i = 2;i*i <=x && i <= 46340; i = i*i) {
            last = i;
        }
        
        return BinarySearch(last, i,x);
    }
    
    int BinarySearch(long long i , long long j, int target){
        long long mid;
        while (i <= j) {
            mid = (i+j)/2;
            
            if (mid*mid <= target && (mid + 1)*(mid + 1) > target)
                return mid;
            if (mid*mid > target)
                j = mid-1;
            if ((mid + 1)*(mid + 1) <= target)
                i = mid + 1;
        }
        //never reach here
        return INT_MAX;
    }
};