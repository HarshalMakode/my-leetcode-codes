class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> index = {-1, -1};

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == target) {
                index[0] = i;
                break;
            }
        }

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == target) {
                index[1] = i;
            }
        }

        return index;
    }
};