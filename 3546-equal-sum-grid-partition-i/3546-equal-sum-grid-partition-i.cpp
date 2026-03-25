class Solution {
public:
    typedef long long ll;
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        ll sum = 0;
        vector<ll> row(m);
        vector<ll> col(n);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                row[i] += grid[i][j];
                col[j] += grid[i][j];
                sum += grid[i][j];
            }
        }

        if (sum % 2 != 0) {
            return false;
        }

        sum = sum / 2;

        ll upperRow = 0;
        for (int i = 0; i < m-1; i++) {
            upperRow += row[i];
            if (upperRow == sum)
                return true;
        }

        ll upperCol = 0;
        for (int i = 0; i < n-1; i++) {
            upperCol += col[i];
            if (upperCol == sum)
                return true;
        }

        return false;
    }
};