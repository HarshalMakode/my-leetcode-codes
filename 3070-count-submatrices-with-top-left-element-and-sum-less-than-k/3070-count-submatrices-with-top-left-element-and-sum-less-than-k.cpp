// class Solution {
// public:
//     int countSubmatrices(vector<vector<int>>& grid, int k) {
//         int m = grid.size();
//         int n = grid[0].size();
//         int count = 0;

//         for(int i = 0; i < m; i++) {
//             for(int j = 0; j < n; j++) {
//                 int sum = 0;
//                 for(int a = 0; a <= i; a++) {
//                     for(int b = 0; b <= j; b++) {
//                         sum += grid[a][b];
//                     }
//                 }

//                 if(sum <= k) {
//                     count++;
//                 }
//             }
//         }

//         return count;
//     }
// };


class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                
                if(i > 0) grid[i][j] += grid[i-1][j];   //above
                if(j > 0) grid[i][j] += grid[i][j-1];   //left
                if(i > 0 && j > 0) grid[i][j] -= grid[i-1][j-1];   //- previous diagonal

                if(grid[i][j] <= k) {
                    count++;
                }
            }
        }

        return count;
    }
};