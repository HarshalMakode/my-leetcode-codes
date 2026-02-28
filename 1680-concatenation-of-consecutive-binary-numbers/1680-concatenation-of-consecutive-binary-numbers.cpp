class Solution {
public:
    int M = 1e9+7;
    int concatenatedBinary(int a) {
        long long result = 0;

        for(int i = 1; i <= a; i++) {
            int digit = log2(i) + 1;

            result = ((result << digit) % M + i) % M;
        }

        return result;
    }
};