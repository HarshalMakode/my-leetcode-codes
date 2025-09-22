class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {

        unordered_map<int, int> mp;

        int n = nums.size();
        int max_count = 0;
        int count = 0;

        for(int i = 0; i < n; i++) {
            mp[nums[i]]++;
            max_count = max(max_count, mp[nums[i]]);
        }

        for(auto &i: mp) {
            if(i.second == max_count) {
                count = count + i.second;
            }
        }
        return count;
    }
};