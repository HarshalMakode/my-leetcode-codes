// //recursion + memorization

// class Solution {
// public:
//     int m, n;

//     int solve(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& t) {

//         if(i >= m || j >= n) {
//             return 0;
//         }

//         if(matrix[i][j] == 0) {
//             return 0;
//         }

//         if(t[i][j] != -1) {
//             return t[i][j];
//         }

//         int right = solve(i, j+1, matrix, t);
//         int diag = solve(i+1, j+1, matrix, t);
//         int left = solve(i+1, j, matrix, t);

//         return t[i][j] = 1 + min({right, diag, left});
//     }

//     int countSquares(vector<vector<int>>& matrix) {
//         m = matrix.size();
//         n = matrix[0].size();

//         int result = 0;

//         vector<vector<int>> t(m+1, vector<int> (n+1, -1));

//         for(int i = 0; i< m; i++) {
//             for(int j = 0; j< n; j++) {
//                 if(matrix[i][j] == 1) {
//                     result += solve(i, j, matrix , t);
//                 }
//             }
//         }

//         return result;
//     }
// };

//bottom up

class Solution {
public:
    int m, n;

    int countSquares(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();

        int result = 0;

        vector<vector<int>> t(m+1, vector<int> (n+1, 0));

        for(int i = 0; i< m; i++) {
            for(int j = 0; j< n; j++) {

                if(i == 0 || j == 0) { //base case
                    t[i][j] = matrix[i][j];
                } else if(matrix[i][j] == 1) {
                    // Because, if you have any 0, then you cannot expand side of square

                    t[i][j] = 1 + min({t[i-1][j], t[i][j-1], t[i-1][j-1]});
                }

                result += t[i][j];
            }

        }

        return result;
    }
};