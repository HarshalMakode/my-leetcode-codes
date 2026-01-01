class Solution {
public:

    void solve(vector<int>& nums, int index,  set<vector<int>>& res, vector<int>& subset) {
        if(index == nums.size()) {
            res.insert(subset);
            return;
        }

        subset.push_back(nums[index]);
        solve(nums, index + 1, res, subset);
        subset.pop_back();
        solve(nums, index + 1, res, subset);

    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> res;
        vector<int> subset;
        sort(nums.begin(), nums.end());
        solve(nums, 0, res, subset);
        vector<vector<int>> result;
        for(auto i: res) {
            result.push_back(i);
        }
        return result;
    }
};