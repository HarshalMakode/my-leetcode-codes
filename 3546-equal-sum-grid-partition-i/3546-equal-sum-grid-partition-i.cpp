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

        ll upperRow = 0;
        for (int i = 0; i < m; i++) {
            upperRow += row[i];
            ll lowerRow = sum - upperRow;
            if (lowerRow == upperRow)
                return true;
        }

        ll upperCol = 0;
        for (int i = 0; i < n; i++) {
            upperCol += col[i];
            ll lowerCol = sum - upperCol;
            if (lowerCol == upperCol)
                return true;
        }

        return false;
    }
};