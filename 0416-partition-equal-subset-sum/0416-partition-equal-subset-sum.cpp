class Solution {
public:
    bool solve(int i, int sum, vector<int>& nums,  vector<vector<int>>& dp) {
        if(sum == 0) return true;
        if(i == 0) return (nums[0] == sum);

        if(dp[i][sum] != -1) return dp[i][sum];

        bool not_take = solve(i-1, sum, nums, dp);

        bool take = false;

        if(nums[i] <= sum) 
            take = solve(i-1, sum - nums[i], nums, dp);

        return dp[i][sum] = take | not_take;
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum += nums[i];
        }

        if(sum%2 != 0) return false;

        sum = sum/2;

        vector<vector<int>> dp(n+1, vector<int>(sum+1, -1));  //plus 1 to avoid overflow

        return solve(n-1, sum, nums, dp);
    }
};