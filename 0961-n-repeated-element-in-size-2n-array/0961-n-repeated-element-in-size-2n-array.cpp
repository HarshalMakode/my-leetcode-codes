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


class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        for (int i = 0; i < A.size() - 2; ++i)
            if (A[i] == A[i + 1] || A[i] == A[i + 2])
                return A[i];
        return A.back();
    }
};
