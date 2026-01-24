class Solution {
    public int minPairSum(int[] nums) {
        int left = 0;
        int right = nums.length-1;

        Arrays.sort(nums);

        int maxi = Integer.MIN_VALUE;
        while(left < right) {
            maxi = Math.max(maxi, nums[left] + nums[right]);
            System.out.println(maxi + "\n" + (nums[left] + nums[right]) + "\n");
            left++;
            right--;
        }

        return maxi;
    }
}