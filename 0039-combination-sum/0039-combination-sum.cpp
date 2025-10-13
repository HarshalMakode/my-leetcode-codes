class Solution {
public:

    vector<vector<int>> result;

    void solve(int i, vector<int>& candidates, int n, int target, vector<int> curr) {
        
        if (target == 0) { 
            result.push_back(curr);
            return;
        }
        
        if(i >= n || target < 0) {
            return;
        }

        curr.push_back(candidates[i]);
        solve(i, candidates, n, target - candidates[i], curr);
        curr.pop_back();
        solve(i+1, candidates, n, target, curr);        
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<int> curr;
        solve(0, candidates, n, target, curr);
        return result;
    }
};