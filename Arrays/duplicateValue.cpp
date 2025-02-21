#include<iostream>
#include<vector>
#include <unordered_map>

class Solution {
    public:
        int findDuplicate(std::vector<int>& nums) {
            std::unordered_map<int, int> dict;
            int maxFreq = 0, mostFrequent = -1;

            for (int num : nums) {
                dict[num]++;

                if (dict[num] > maxFreq) {
                    maxFreq = dict[num];
                    mostFrequent = num;
                }
            }

            return mostFrequent;
        }
};

int main() {
    Solution s1;
    std::vector<int> nums = {1,3,4,2,2};
    std::cout << "Most frequent number: " << s1.findDuplicate(nums) << std::endl;
    return 0;
}