class Solution {
public:

    void solve(int i, int sum, int k, int n,  vector<int>& subset, vector<vector<int>>& res) {
        if(sum == n && subset.size() == k) {
            res.push_back(subset);
            return;
        }

        if(sum > n || i == 10 || subset.size() == k) {
            return;
        }

        subset.push_back(i);
        solve(i+1, sum+i, k, n, subset, res);
        subset.pop_back();
        solve(i+1, sum, k, n, subset, res);

    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> subset;
        solve(1, 0, k, n, subset, res);
        return res;
    }
};