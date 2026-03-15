class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;

        if(N == 0)
            return 1;

        if(N < 0) {
            x = 1 / x;
            N = -N;
        }

        double half = myPow(x, N/2);

        double result = half * half;

        if(N % 2 == 1)
            result *= x;

        return result;
    }
};