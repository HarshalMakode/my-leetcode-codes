class Solution {
    public int minimumDifference(int[] nums, int k) {
        int n = nums.length;

        int result = Integer.MAX_VALUE;

        int i = 0;
        int j = k - 1;

        Arrays.sort(nums);

        while(j < n) {
            int mini = nums[i];
            int maxi = nums[j];

            result = Math.min(result, maxi - mini);

            i++;
            j++;
        }

        return result;
    }
}