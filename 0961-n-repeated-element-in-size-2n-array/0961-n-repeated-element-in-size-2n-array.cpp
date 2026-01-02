// class Solution {
// public:
//     int repeatedNTimes(vector<int>& nums) {
//         unordered_map<int, int> mp;
//         int maxCount = 0;
//         int maxIndex = 0;

//         for(auto i: nums) {
//             mp[i]++;
//         }

//         for(auto i: mp) {
//             if(maxCount < i.second) {
//                 maxCount = i.second;
//                 maxIndex = i.first;
//             }
//         }

//         return maxIndex;
//     }
// };

// //Pigeonhole Principle
// class Solution {
// public:
//     int repeatedNTimes(vector<int>& A) {
//         for (int i = 0; i < A.size() - 2; ++i)
//             if (A[i] == A[i + 1] || A[i] == A[i + 2])
//                 return A[i];
//         return A.back();
//     }
// };


class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int, int> mp;

        for(auto i: nums) {
            mp[i]++;
            if(mp[i] > 1) {
                return i;
            }
        }

        return nums[nums.size() -1];
    }
};
