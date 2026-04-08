class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& grid, int mini, vector<vector<int>>& dp) {
        if(i == 0 && j == 0) return grid[0][0];
        if(i < 0 || j < 0) return INT_MAX;
        if(dp[i][j] != -1) return dp[i][j];
        long long up = (long long) grid[i][j] + solve(i-1, j, grid, mini, dp);
        long long left = (long long) grid[i][j] + solve(i, j-1, grid, mini, dp);

        return dp[i][j] = min(up, left);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int mini = INT_MAX;
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(m-1, n-1, grid, mini, dp);
    }
};