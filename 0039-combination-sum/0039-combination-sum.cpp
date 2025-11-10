// class Solution {
// public:

//     vector<vector<int>> result;

//     void solve(int i, vector<int>& candidates, int n, int target, vector<int> curr) {
        
//         if (target == 0) { 
//             result.push_back(curr);
//             return;
//         }
        
//         if(i >= n || target < 0) {
//             return;
//         }

//         curr.push_back(candidates[i]);
//         solve(i, candidates, n, target - candidates[i], curr);
//         curr.pop_back();
//         solve(i+1, candidates, n, target, curr);        
//     }

//     vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//         int n = candidates.size();
//         vector<int> curr;
//         solve(0, candidates, n, target, curr);
//         return result;
//     }
// };


class Solution {
public:

    set<vector<int>> s;

    void getAllCombinations(vector<int>& arr, int i, int target, vector<vector<int>>& ans, vector<int>& combin) {

        if(i == arr.size() || target < 0) {
            return;
        }

        if(target == 0) {
            if(s.find(combin) == s.end()) {
                ans.push_back(combin);
                s.insert(combin);
            }

           
            return;
        }
        
        combin.push_back(arr[i]);
        //single
        getAllCombinations(arr, i+1, target - arr[i], ans, combin);

        //multiple
        getAllCombinations(arr, i, target - arr[i], ans, combin);

        combin.pop_back();

        //exclusion
        getAllCombinations(arr, i+1, target, ans, combin);

    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> combin;

        getAllCombinations(candidates, 0, target, ans, combin);

        return ans;
    }
};