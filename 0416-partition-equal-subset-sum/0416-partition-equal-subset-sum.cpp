// class Solution {
// public:
//     bool solve(int i, int sum, vector<int>& nums,  vector<vector<int>>& dp) {
//         if(sum == 0) return true;
//         if(i == 0) return (nums[0] == sum);

//         if(dp[i][sum] != -1) return dp[i][sum];

//         bool not_take = solve(i-1, sum, nums, dp);

//         bool take = false;

//         if(nums[i] <= sum) 
//             take = solve(i-1, sum - nums[i], nums, dp);

//         return dp[i][sum] = take | not_take;
//     }

//     bool canPartition(vector<int>& nums) {
//         int n = nums.size();

//         int sum = 0;
//         for(int i = 0; i < n; i++) {
//             sum += nums[i];
//         }

//         if(sum%2 != 0) return false;

//         sum = sum/2;

//         vector<vector<int>> dp(n+1, vector<int>(sum+1, -1));  //plus 1 to avoid overflow

//         return solve(n-1, sum, nums, dp);
//     }
// };

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum += nums[i];
        }

        if(sum%2 != 0) return false;

        sum = sum/2;

        vector<vector<bool>> dp(n+1, vector<bool>(sum+1, false));

        for(int i = 0; i < n; i++) 
            dp[i][0] = true;

        if(nums[0] <= sum) dp[0][nums[0]] = true; 

        for(int i = 1; i < n; i++) { 
            for(int k = 1; k <= sum; k++) { 
                bool not_take = dp[i-1][k];
                bool take = false;

                if(nums[i] <= k) 
                    take = dp[i-1][k - nums[i]];

                dp[i][k] = take | not_take;
            } 
        }

        return dp[n-1][sum];
    }
};