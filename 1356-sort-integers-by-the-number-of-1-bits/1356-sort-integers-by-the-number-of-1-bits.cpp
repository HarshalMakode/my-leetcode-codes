class Solution {
public:
    int find1bitCount(int n) {
        int count = 0;

        while (n != 0) {
            count += (n & 1);
            n >>= 1;
        }

        return count;
    }

    vector<int> sortByBits(vector<int>& arr) {
        auto lambda = [&](int& a, int& b) { // capture clause
            int cA = find1bitCount(a);
            int cB = find1bitCount(b);

            if (cA == cB)
                return a < b;

            return cA < cB;
        };

        sort(begin(arr), end(arr), lambda);

        return arr;
    }
};