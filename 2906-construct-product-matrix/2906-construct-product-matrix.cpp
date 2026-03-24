class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int M = 12345;
        vector<vector<int>> result(m, vector<int>(n));

        long long suffix = 1;
        for(int i = m-1; i >= 0; i--) {
            for(int j = n-1; j >= 0; j--) {
                result[i][j] = suffix;
                suffix = (suffix * grid[i][j]) % M;
            }
        }

        long long prefix = 1;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                result[i][j] = (prefix * result[i][j]) % M;
                prefix = (prefix * grid[i][j]) % M;
            }
        }

        return result;
    }
};