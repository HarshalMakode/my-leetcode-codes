// class Solution {
// public:
//     vector<int> searchRange(vector<int>& nums, int target) {
//         vector<int> index = {-1, -1};

//         for(int i = 0; i < nums.size(); i++) {
//             if(nums[i] == target) {
//                 index[0] = i;
//                 break;
//             }
//         }

//         for(int i = 0; i < nums.size(); i++) {
//             if(nums[i] == target) {
//                 index[1] = i;
//             }
//         }

//         return index;
//     }
// };


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = -1;
        int right = -1;
        int l = 0;
        int h = nums.size() - 1;

        while(l <= h) {

            int m = l + (h - l) / 2;

            if(nums[m] == target) {
                left = m;
                h = m - 1;
            } else if(nums[m] < target) {  
                l = m + 1;
            } else {
                h = m - 1;
            }

        }

        l = 0;
        h = nums.size() - 1;

        while(l <= h) {

            int m = l + (h - l) / 2;

            if(nums[m] == target) {
                right = m;
                l = m + 1;
            } else if(nums[m] < target) {  
                l = m + 1;
            } else {
                h = m - 1;
            }

        }

        return {left, right};
    }
};