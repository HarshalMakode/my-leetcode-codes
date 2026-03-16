class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        int n = nums.size();
        for(int left = 0; left < n; left++) {
            int sum = 0;
            int right = left;
            while(right < n) {
                sum += nums[right];
                if (sum == k) {
                    count++;
                }
                right++;
            }
        }
        return count;
    }
};