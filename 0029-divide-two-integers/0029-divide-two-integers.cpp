class Solution {
public:
    int divide(int dividend, int divisor) {
        if((long)dividend/divisor == (long)INT_MAX+1) {
            return INT_MAX;
        }
        return (int)dividend/divisor;
    }
};