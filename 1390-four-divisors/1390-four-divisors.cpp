class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int sum = 0;
        unordered_map<int, vector<int>> mp;
        unordered_map<int, int> freq;

        for(int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
            if (mp.count(nums[i])) continue;
            for(int j = 1; j * j <= nums[i]; j++) {
                if (nums[i] % j == 0) {
                    mp[nums[i]].push_back(j);
                    if (j != nums[i] / j) {
                        mp[nums[i]].push_back(nums[i] / j);
                    }
                    if (mp[nums[i]].size() > 4) break;
                }
            }

        }

        for (auto i : mp) {
            if (i.second.size() == 4) {
                int temp = 0;
                for (int x : i.second) temp += x;
                sum += temp * freq[i.first];
            }
        }

        return sum;
    }
};