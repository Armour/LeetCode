class Solution {
public:
    int divide(int dividend, int divisor) {
        //handle special cases
        if (divisor == 0) return INT_MAX;
        if (divisor == -1 && dividend == INT_MIN)
            return INT_MAX;
     
        //get positive values
        long pDividend = abs((long long)dividend);
        long pDivisor = abs((long long)divisor);
     
        int result = 0;
        while (pDividend >= pDivisor) {
            //calculate number of left shifts
            int numShift = 0;    
            while (pDividend >= (pDivisor << numShift)) {
                numShift++;
            }
     
            //dividend minus the largest shifted divisor
            result += 1 << numShift - 1;
            pDividend -= (pDivisor << numShift - 1);
        }
     
        if ((dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0)) {
            return result;
        } else {
            return -result;
        }
    }
};
