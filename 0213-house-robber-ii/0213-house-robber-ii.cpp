class Solution {
public:
    int solve(vector<int>& nums, int start, int end) {
        int prev2 = 0;
        int prev1 = 0;

        for(int i = start; i < end; i++) {
            int pick = nums[i] + prev2;
            int notpick = prev1;

            int curr = max(pick, notpick);

            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) {
            return nums[0];
        }

        return max(solve(nums, 0, n-1), solve(nums, 1, n));
    }
};