// class Solution {
// public:
//     int solve(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>&
//     dp) {
//         int n = matrix.size();

//         if (j < 0 || j >= n) return INT_MAX;
//         if (i == 0) return matrix[0][j];

//         if (dp[i][j] != -1) return dp[i][j];

//         int up = solve(i - 1, j, matrix, dp);
//         int right = solve(i - 1, j + 1, matrix, dp);
//         int left = solve(i - 1, j - 1, matrix, dp);

//         int s = (up == INT_MAX) ? INT_MAX : matrix[i][j] + up;
//         int r = (right == INT_MAX) ? INT_MAX : matrix[i][j] + right;
//         int l = (left == INT_MAX) ? INT_MAX : matrix[i][j] + left;

//         return dp[i][j] = min({s, r, l});
//     }

//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         int n = matrix.size();

//         vector<vector<int>> dp(n, vector<int>(n, -1));

//         int ans = INT_MAX;
//         for (int j = 0; j < n; j++) {
//             ans = min(ans, solve(n - 1, j, matrix, dp));
//         }

//         return ans;
//     }
// };

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        vector<int> dp(n, 0);

        for (int j = 0; j < n; j++) {
            dp[j] = matrix[0][j];
        }

        for (int i = 1; i < n; i++) {
            vector<int> curr(n, 0);
            for (int j = 0; j < n; j++) {
                int s = matrix[i][j] + dp[j];
                int l = INT_MAX;
                if (j - 1 >= 0)
                    l = matrix[i][j] + dp[j - 1];

                int r = INT_MAX;
                if (j + 1 < n)
                    r = matrix[i][j] + dp[j + 1];

                curr[j] = min({s, r, l});
            }
            dp = curr;
        }

        int ans = INT_MAX;
        for (int j = 0; j < n; j++) {
            ans = min(ans, dp[j]);
        }

        return ans;
    }
};