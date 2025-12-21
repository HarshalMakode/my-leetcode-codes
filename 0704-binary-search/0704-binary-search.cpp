
// linear search

// class Solution {
// public:
//     int search(vector<int>& nums, int target) {
//         for(int i = 0; i< nums.size(); i++) {
//             if(nums[i] == target) {
//                 return i;
//             }
//         }
//         return -1;
//     }
// };

// class Solution {
// public:
//     int search(vector<int>& nums, int target) {
//         int n = nums.size();
//         int l = 0;
//         int h = n - 1;

//         while(l <= h) {

//             int m = l + (h - l) / 2;

//             if(nums[m] == target) {
//                 return m;
//             } else if(nums[m] < target) {    // for decending or unsorted
//             array just change the operator to '>'
//                 l = m + 1;
//             } else {
//                 h = m - 1;
//             }

//         }

//         return -1;
//     }
// };

class Solution {
public:
    int binary(vector<int>& nums, int target, int l, int h) {
        if (l > h)
            return -1;

        int m = l + (h - l) / 2;

        if (nums[m] == target) {
            return m;
        } else if (nums[m] < target) {
            l = m + 1; // move right
        } else {
            h = m - 1; // move left
        }

        return binary(nums, target, l, h);
    }

    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int h = n - 1;

        int index = binary(nums, target, l, h);

        return index;
    }
};