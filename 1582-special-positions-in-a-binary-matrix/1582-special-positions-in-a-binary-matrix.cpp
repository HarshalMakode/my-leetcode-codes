class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int k = 0; k < n; k++) {

                int countRow1 = 0;
                for (int j = 0; j < n; j++) {
                    if (mat[i][j] == 1) {
                        countRow1++;
                    }
                }

                int countColumn1 = 0;
                for (int j = 0; j < m; j++) {
                    if (mat[j][k] == 1) {
                        countColumn1++;
                    }
                }

                if(mat[i][k] == 1 && countRow1 == 1 && countColumn1 == 1) {
                    count++;
                } 
            }
        }
        return count;
    }
};