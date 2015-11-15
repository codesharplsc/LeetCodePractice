
1.
/*
5 servers in total. 
We assume i is the last server that handles the request, j is the next server that the algorithm returns.
*/
 j = i;
 do{
    j = (j+1) % 5;
    if( j is available){
        i = j;
        return j;
    }

 }while(j!= i);


/*
5 servers in total.
We may assume they are 


*/




while (true) {
    i = (i + 1) %5;
    if (i == 0) {
        cw = cw - gcd(S); 
        if (cw <= 0) {
            cw = max(S);
            if (cw == 0)
            return NULL;
        }
    } 
    if (W(Si) >= cw) 
        return Si;
}







2.
/*
 The function first uses shift method to check x is in the range of[7*2^(i-1),7*2^i],
 then use binary search to search between this range to find the quotient
 
 @param x is the numerator
 @return the result divided by 7, -1 indicate negative number.
 */
int DivideBy7(int x){
    int i = 1;
    
    long Low = 0, High = 7, MidLow = 0, MidHigh = 0;
    int result  = 0;
    
    if(x<0)
        return -1;
    if(x<=7)
        return x/7;
    
    while(1){
        Low  = High;
        High = 7<<i;
        if(x>=Low && x<= High)
            break;
        i++;
    }
    
    MidLow  = 1<<(i-1);
    MidHigh = 1<<i;
    while(1){
        result = (MidLow+MidHigh)>>1;
        if(x-(result*7)<7&&x >=result*7)
            break;
        if(x-(result*7)>7)
            MidLow = result;
        if(x-(result*7) == 7)
            return result+1;
        if((result*7)>x)
            MidHigh = result;
        
    }
    return result;
}



