class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int l = 0;
        int r = 0;
        int n = nums.size();
        int maxi = 1;
        int mask = 0;

        while(r < n) {
            while(l < r && (mask & nums[r]) != 0) {
                mask ^= nums[l];
                l++;
            }

            mask |= nums[r];

            maxi = max(maxi, r - l + 1);

            r++;
        }

        return maxi;
    }
};