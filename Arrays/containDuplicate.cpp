#include<iostream>
#include<vector>
#include <algorithm>

class Solution {
    public:
        bool containsDuplicate(std::vector<int>& nums) {
            std::sort(nums.begin(), nums.end());
            for (size_t i = 1; i < nums.size(); i++)  
                if (nums[i] == nums[i - 1]) 
                    return true;
            return false;
        }
    };

int main() {
    Solution s1;
    std::vector<int> nums = {1,3,4,2,2};
    std::cout << "Most frequent number: " << s1.containsDuplicate(nums) << std::endl;
    return 0;
}