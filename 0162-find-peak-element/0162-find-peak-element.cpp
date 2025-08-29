// class Solution {
// public:
//     int findPeakElement(vector<int>& nums) {
//         int n = nums.size();
//         int l = 0;
//         int h = n - 1;

//         while(l < h) {
//             int m = l + (h - l) / 2;
            
//             if(nums[m] > )
//         } 
//     }
// };


class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if((i == 0 || nums[i-1] < nums[i]) && (i == n-1 || nums[i] > nums[i+1])) {
                return i;
            }
        }
        return -1;
    }
};