// class Solution {
// public:
//     int divide(int dividend, int divisor) {
//         if((long)dividend/divisor == (long)INT_MAX+1) {
//             return INT_MAX;
//         }
//         return (int)dividend/divisor;
//     }
// };
// 

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == divisor) return 1;

        bool sign = true;

        if(dividend >= 0 && divisor < 0) sign = false;
        if(dividend < 0 && divisor > 0) sign = false;
        

        long n = labs(dividend);
        long d = labs(divisor);
        long result = 0;

        while(n >= d) {
            int count = 0;
            while(n >= (d << (count+1))) {
                count++;
            }
            result += (1l << count);
            n = n - (d * (1l << count));
        }

        if(result == (1l<<31) && sign) return INT_MAX;
        if(result == (1l<<31) && !sign) return INT_MIN;

        return sign ? result : -result;
    }
};