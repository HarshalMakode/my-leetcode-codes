// class Solution {
// public:
//     vector<int> shuffle(vector<int>& nums, int n) {

//         vector<int> ans(2*n);
//         int j = 0;
//         for(int i = 0; i < n*2; i+=2) {
//             ans[i] = nums[j];
//             ans[i+1] = nums[j+n];
//             j++;
//         }

//         return ans;
//     }
// };


class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> res;
        for (int i = 0; i < n; i++) {
            res.push_back(nums[i]);
            res.push_back(nums[i + n]);
        }
        return res;
    }
};