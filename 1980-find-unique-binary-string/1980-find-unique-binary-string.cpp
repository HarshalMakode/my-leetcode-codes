class Solution {
public:
    bool solve(int n, string& curr, unordered_set<string>& seen, string& result) {
        if (curr.length() == n) {
            if (seen.find(curr) == seen.end()) {
                result = curr;
                return true;
            }
            return false;
        }

        // Try '0'
        curr.push_back('0');
        if (solve(n, curr, seen, result)) return true;
        curr.pop_back(); // Backtrack

        // Try '1'
        curr.push_back('1');
        if (solve(n, curr, seen, result)) return true;
        curr.pop_back(); // Backtrack

        return false;
    }

    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<string> seen(nums.begin(), nums.end());
        string result = "";
        string curr = "";
        solve(nums.size(), curr, seen, result);
        return result;
    }
};