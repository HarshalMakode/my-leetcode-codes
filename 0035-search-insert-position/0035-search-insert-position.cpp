//linear search solution

// class Solution {
// public:
//     int searchInsert(vector<int>& nums, int target) {
//         int index = -1;
//         for(int i = 0; i < nums.size(); i++) {
//             if(nums[i] == target) {
//                 return i;
//             }
//             if(nums[i] < target) {
//                 index = i;
//             }
//         }
//         return index+1;
//     }
// };


class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int low = 0; 
        int high = nums.size() - 1;

        while(low <= high) {
            
            int mid = low + (high -low) / 2;
                        
            if(nums[mid] == target) {
                return mid;
            } else if(nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }

        }


        return low;
    }
};