class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> result;

        for (int i = x; i < x + k; i++) {
            vector<int> row;
            for (int j = y; j < y + k; j++) {
                row.push_back(grid[i][j]);
            }
            result.push_back(row);
        }

        for (int i = x; i < x + k; i++) {
            for (int j = y; j < y + k; j++) {
                grid[i][j] = result[k - 1 - (i - x)][j - y];
            }
        }

        return grid;
    }
};