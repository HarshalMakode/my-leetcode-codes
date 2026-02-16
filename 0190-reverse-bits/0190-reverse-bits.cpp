class Solution {
public:
    int reverseBits(int n) {
        unsigned int result = 0;

        for (int i = 0; i < 32; i++) {
            result <<= 1;      // shift left to make space
            result |= (n & 1); // take last bit of n and insert it to that space
            n >>= 1;           // remove last bit of n
        }

        return result;
    }
};