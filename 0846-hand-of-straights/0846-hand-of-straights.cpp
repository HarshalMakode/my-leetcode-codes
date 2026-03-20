class Solution {
public:
    bool isNStraightHand(vector<int>& nums, int k) {
        if (nums.size() % k != 0) {
            return false;
        }

        int n = nums.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        unordered_map<int, int> mp;

        for (int i : nums) {
            mp[i]++;
        }

        for (auto i : mp) {
            pq.push(i.first);
        }

        while (!pq.empty()) {
            int start = pq.top();
            pq.pop();

            if (mp[start] == 0)
                continue;

            for (int i = 0; i < k; i++) {
                int curr = start + i;

                if (mp[curr] == 0)
                    return false;

                mp[curr]--;
            }

            if(mp[start] > 0) {
                pq.push(start);
            }
        }

        return true;
    }
};