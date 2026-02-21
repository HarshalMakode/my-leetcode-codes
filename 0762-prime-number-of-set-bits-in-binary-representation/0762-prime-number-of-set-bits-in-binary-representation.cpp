class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int countPrime = 0;
        for(int i = left; i <= right; i++) {
            int count = 0;
            int n = i;
            while(n != 0) {
                n = (n & (n-1));
                count++;
            }
            if(count == 2 || count == 3 || count == 5 || count == 7 || count == 11 || count == 13 || count == 17 || count == 19) {
                countPrime++;
            }
        }

        return countPrime;
    }
};