class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        unordered_map<int, int> mp;
        for(int x : friends) mp[x]++;

        // Iterate backwards to safely erase elements
        for(int i = order.size() - 1; i >= 0; i--) {
            if(mp.find(order[i]) == mp.end()) {
                order.erase(order.begin() + i);
            }
        }

        return order;
    }
};
