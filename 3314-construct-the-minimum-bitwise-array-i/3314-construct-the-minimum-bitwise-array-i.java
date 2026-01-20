class Solution {
    public int[] minBitwiseArray(List<Integer> nums) {
        int n = nums.size();
        int[] ans = new int[n];
        for(int i = 0; i < n; i++) {
            int mini = Integer.MAX_VALUE;
            int target = nums.get(i);
            for (int x = 0; x <= target; x++) {
                if ( (x | (x + 1)) == target ) {
                    mini = Math.min(mini, x);
                }
            }
            ans[i] = (mini == Integer.MAX_VALUE) ? -1 : mini;
        }

        return ans;
    }
}