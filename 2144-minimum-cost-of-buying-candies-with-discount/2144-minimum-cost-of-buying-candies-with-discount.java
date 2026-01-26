class Solution {
    public int minimumCost(int[] cost) {
        Arrays.sort(cost);
        int result = 0;
        int n = cost.length;
        int j = 1;

        for(int i = n - 1; i >= 0; i--) {
            if(j == 3 ) {
                j = 1;
                continue;
            }
            result += cost[i];
            j++;
        }

        return result;
    }
}