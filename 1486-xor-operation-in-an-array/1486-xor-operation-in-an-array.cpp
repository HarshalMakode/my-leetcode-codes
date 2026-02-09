class Solution {
public:
    int xorOperation(int n, int start) {
        int XOR = start;

        for(int i = 1; i < n; i++) {
            int num = start + 2*i;
            XOR = XOR ^ num;
        }

        return XOR;
    }
};