class Solution {
    public int minBitFlips(int start, int goal) {
        int result = 0;

        int xor = start ^ goal;

        while(xor!=0){
            result = result + (xor & 1);
            xor = xor >> 1;
        }
        return result;
    }
}