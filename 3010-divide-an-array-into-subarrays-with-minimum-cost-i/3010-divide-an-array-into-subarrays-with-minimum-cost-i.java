class Solution {
    public int minimumCost(int[] nums) {
        int result = nums[0];

        int a = Integer.MAX_VALUE;
        int b = Integer.MAX_VALUE;

        for(int i = 1; i < nums.length; i++) {
            if(nums[i] < a) {
                b = a;
                a = nums[i];
            } else if(nums[i] < b) {
                b = nums[i];
            }
        }

        return result + a + b;
    }
}