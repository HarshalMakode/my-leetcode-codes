class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int, int> mp;
        int maxCount = 0;
        int maxIndex = 0;

        for(auto i: nums) {
            mp[i]++;
        }

        for(auto i: mp) {
            if(maxCount < i.second) {
                maxCount = i.second;
                maxIndex = i.first;
            }
        }

        return maxIndex;
    }
};