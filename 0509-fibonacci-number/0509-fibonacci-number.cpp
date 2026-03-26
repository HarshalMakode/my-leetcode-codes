// class Solution {
// public:
//     int solve(int n, vector<int>& dp) {
//         if (n <= 1)
//             return n;

//         if (dp[n] != -1)
//             return dp[n];

//         return dp[n] = solve(n - 1, dp) + solve(n - 2, dp);
//     }

//     int fib(int n) {
//         vector<int> dp(n + 1, -1);
//         return solve(n, dp);
//     }
// };

// class Solution {
// public:
//     int fib(int n) {
//         vector<int> dp2(n + 1, -1);
//         dp2[0] = 0;
//         dp2[1] = 1;

//         for (int i = 2; i <= n; i++) {
//             dp2[i] = dp2[i - 1] + dp2[i - 2];
//         }

//         return dp2[n];
//     }
// };

class Solution {
public:
    int fib(int n) {
        if(n == 0) return 0;

        int prev2 = 0;
        int prev1 = 1;

        for (int i = 2; i <= n; i++) {
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};