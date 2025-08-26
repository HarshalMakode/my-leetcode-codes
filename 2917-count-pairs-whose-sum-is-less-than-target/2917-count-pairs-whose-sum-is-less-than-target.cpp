// class Solution {
// public:
//     int countPairs(vector<int>& nums, int target) {
//         int n = nums.size();
//         int count = 0;
//         for(int i = 0; i < n; i++) {
//             for(int j = i+1; j < n; j++) {
//                 if(nums[i] + nums[j] < target) {
//                     count++;
//                 }
//             }
//         }
//         return count;
//     }
// };


class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end()); // step 1
        int n = nums.size();
        int i = 0, j = n - 1;
        int count = 0;

        while(i < j) {
            if(nums[i] + nums[j] < target) {
                count += (j - i);  // all pairs (i, i+1 ... j)
                i++;
            } else {
                j--;
            }
        }
        return count;
    }
};
