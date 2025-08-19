// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         vector<int> result;

//         int n = nums.size();

//         bool ok = false;

//         for(int i = 0; i< n; i++) {
//             for(int j = 0; j < n; j++) {
//                 if(i == j) {
//                     continue;
//                 }

//                 if((nums[i] + nums[j]) == target) {
//                     result.push_back(i);
//                     result.push_back(j);
//                     ok = true;
//                     break;
//                 }

//             }
//             if(ok) {
//                 break;
//             }
//         }

//         return result;
//     }
// };


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;

        int n = nums.size();

        int t = 0;

        unordered_map<int, int> mp;

        for(int i = 0; i < n; i++) {
            t = target - nums[i];
            if(mp.find(t) != mp.end()) {
                result.push_back(mp[t]);
                result.push_back(i);
                return result;
            }
            mp[nums[i]] = i;
        } 

        return result;
    }
};