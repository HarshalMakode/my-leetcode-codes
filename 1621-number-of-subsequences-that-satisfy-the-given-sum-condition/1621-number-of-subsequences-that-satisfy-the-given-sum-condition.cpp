// class Solution {
// public:
//     int solve(int i, int n, vector<int>& nums, int target, int currMin, int currMax, bool taken) {
//         if (i == n) {
//             if (taken && (currMin + currMax <= target)) 
//                 return 1; 
//             return 0; 
//         }

//         int include = solve(i + 1, n, nums, target,
//                             taken ? min(currMin, nums[i]) : nums[i],
//                             taken ? max(currMax, nums[i]) : nums[i],
//                             true);

//         // Exclude nums[i] from the subsequence
//         int exclude = solve(i + 1, n, nums, target, currMin, currMax, taken);

//         return include + exclude;
//     }

//     int numSubseq(vector<int>& nums, int target) {
//         int n = nums.size();
//         return solve(0, n, nums, target, 0, 0, false);
//     }
// };


class Solution {
public:
    int M = 1e9+7;
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        long long result= 0;
        sort(nums.begin(), nums.end());
        int l = 0;
        int r = n - 1;
        vector<long long> power(n);

        power[0] = 1;

        for(int i = 1; i < n; i++) {
            power[i] = (power[i-1] * 2) % M;
        }

        while(l <= r) {
            if(nums[l] + nums[r] <= target) {
                result = (result % M +  power[r-l]) % M;
                l++;
            } else r--;
        }

        return result;
    }
};
