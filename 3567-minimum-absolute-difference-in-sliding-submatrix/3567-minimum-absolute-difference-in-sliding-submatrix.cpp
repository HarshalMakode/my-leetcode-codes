class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> result(m - k + 1, vector<int>(n - k + 1));

        for(int i = 0; i <= m-k; i++) {
            for(int j = 0; j <= n-k; j++) {
                int mini = INT_MAX;
                
                set<int> st;
                for(int x = i; x < i+k; x++) {
                    for(int y = j; y < j+k; y++) {
                        st.insert(grid[x][y]);
                    }
                }

                for(auto it = st.begin(); next(it) != st.end(); it++) {
                    mini = min(mini, abs(*it - *next(it)));
                }

                if(st.size() <= 1) mini = 0;

                result[i][j] = mini;
            }
        }

        return result;
    }
};