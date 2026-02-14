class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> t(101, vector<double>(101, 0.0));

        t[0][0] = (double)poured;

        for(int i = 0; i <= query_row; i++) {
            for(int j = 0; j <= i; j++) {
                double extra = (t[i][j] - 1)/ 2.0;

                if(extra > 0) {
                    t[i+1][j] += extra;
                    t[i+1][j+1] += extra;
                }
            }
        }
        return min(1.0, t[query_row][query_glass]);
    }
};