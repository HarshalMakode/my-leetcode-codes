class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }

        int result = INT_MAX;

        for(auto &i: mp) {
            auto &v = i.second;
            if(v.size() >= 3) { 
                for (int i = 0; i + 2 < v.size(); i++) {
                    int distance = 2 * (v[i + 2] - v[i]);
                    result = min(result, distance);
                }
            }
        }
        return result == INT_MAX ? -1 : result;
    }
};
