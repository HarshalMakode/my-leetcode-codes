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

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int h = n - 1;

        while(l < h) {

            int m = l + (h - l) / 2;

            if(nums[m] > nums[h]) {
                l = (m+1);
            } else {
                h = m;
            }

        }

        int start = h;
        cout << start;

        l = 0;
        int index = -1;
        h = start - 1; 

        while(l<= h) {
            int m = l + (h - l) / 2;

            if(nums[m] == target) {
                index = m;
                break;
            } else if(nums[m] < target) {
                l = m + 1;
            } else {
                h = m - 1;
            }
        }

        if(index != -1) {
            return index;
        }

        l = start;
        h = n - 1;

        while(l<= h) {
            int m = l + (h - l) / 2;

            if(nums[m] == target) {
                index = m;
                break;
            } else if(nums[m] < target) {
                l = m + 1;
            } else {
                h = m - 1;
            }
        }

        return index;
    }
};