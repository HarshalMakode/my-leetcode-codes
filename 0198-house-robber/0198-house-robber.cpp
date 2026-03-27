// class Solution {
// public:
//     int solve(int i, vector<int>& nums,  vector<int>& dp) {
//         if(i == 0) {
//             return nums[i];
//         }

//         if(i < 0) return 0;

//         if(dp[i] != -1) {
//             return dp[i];
//         }

//         int pick = nums[i] + solve(i-2, nums, dp);
//         int notpick = 0 + solve(i-1, nums, dp);

//         return dp[i] = max(pick, notpick);
//     }

//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> dp(n, -1);
//         return solve(n - 1, nums, dp);
//     }
// };

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return nums[0];

        vector<int> dp(n);

        int prev2 = nums[0];
        int prev1 = max(nums[0], nums[1]);

        for(int i = 2; i < n; i++) {
            int pick = nums[i] + prev2;
            int notpick = 0 + prev1;

            int curr = max(pick, notpick);
            prev2 = prev1;
            prev1 = curr;
        }
    
        return prev1;
    }
};