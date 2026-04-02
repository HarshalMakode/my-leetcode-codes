class Solution {
public:
    int solve(int i, int j, int t, vector<vector<int>>& coins, vector<vector<vector<int>>>& dp) {
        if(i == 0 && j == 0) {
            if(coins[i][j] < 0 && t > 0) {
                return 0;
            }
            return coins[i][j];
        }

        if(i < 0 || j < 0) {
            return INT_MIN;
        }

        if(dp[i][j][t] != INT_MIN) {
            return dp[i][j][t];
        }

        int up = solve(i - 1, j, t, coins, dp);
        int left = solve(i, j - 1, t, coins, dp);

        int take = coins[i][j] + max(up, left);

        int skip = INT_MIN;
        if(coins[i][j] < 0 && t > 0) {
            skip = max(
                solve(i - 1, j, t - 1, coins, dp),
                solve(i, j - 1, t - 1, coins, dp)
            );
        }

        return dp[i][j][t] = max(take, skip);
    }

    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size();
        int n = coins[0].size();

        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n, vector<int>(3, INT_MIN))
        );

        return solve(m-1, n-1, 2, coins, dp);
    }
};