class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int h = n - 1;

        while(l < h) {
            int m = l + (h - l) /2;

            bool even;

            if((h - m) % 2 == 0) {
                even = true;
            } else {
                even = false;
            }
            
            if(nums[m] == nums[m+1]) {
                if(even) {
                    l = m + 2;
                } else {
                    h = m - 1;
                }
            } else {
                if(even) {
                    h = m;
                } else {
                    l = m + 1;
                }
            }
        }

        return nums[h];
    }
};