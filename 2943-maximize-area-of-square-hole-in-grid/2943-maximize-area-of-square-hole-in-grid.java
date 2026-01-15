class Solution {
    public int maximizeSquareHoleArea(int n, int m, int[] hBars, int[] vBars) {
        Arrays.sort(hBars);
        Arrays.sort(vBars);

        int maxConH = 1;
        int maxConV = 1;

        int currConH = 1;
        for(int i = 1; i < hBars.length; i++) {
            if(hBars[i] - hBars[i-1] == 1) {
                currConH++;
            } else {
                currConH = 1;
            }

            maxConH = Math.max(currConH, maxConH);
        }

        int currConV = 1;
        for(int i = 1; i < vBars.length; i++) {
            if(vBars[i] - vBars[i-1] == 1) {
                currConV++;
            } else {
                currConV = 1;
            }

            maxConV = Math.max(currConV, maxConV);
        }

        int side = Math.min(maxConH, maxConV) + 1;
        return side*side;
    }
}