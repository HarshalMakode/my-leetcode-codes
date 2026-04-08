class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int M = 1e9+7;
        for(int i = 0; i < queries.size(); i++) {
            int idx = queries[i][0];
            while(idx <= queries[i][1]) {
                nums[idx] = ((long long)nums[idx] * queries[i][3]) % M;
                idx += queries[i][2];
            }
        }

        int XOR = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            XOR ^= nums[i];
        }

        return XOR;
    }
};