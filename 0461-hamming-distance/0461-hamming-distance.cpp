class Solution {
public:
    int hammingDistance(int x, int y) {
        int XOR = x ^ y;
        int result = 0;

        while(XOR != 0) {
            result += (XOR & 1);
            XOR = XOR >> 1;
        }

        return result;
    }
};