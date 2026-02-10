class Solution {
public:
    int minBitFlips(int start, int goal) {
        int result = 0;

        int XOR = start ^ goal;

        while(XOR!=0){
            result = result + (XOR & 1);
            XOR = XOR >> 1;
        }

        return result;
    }
};