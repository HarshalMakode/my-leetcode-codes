// class Solution {
// public:
//     long long flowerGame(int n, int m) {
//         long long count = 0;
//         for(int i = 1; i <= n; i++) {
//             for(int j = 1; j <= m; j++) {
//                 if((i+j) % 2 != 0) {
//                     count++;
//                 }
//             }
//         }
//         return count;
//     }
// };

class Solution {
public:
    long long flowerGame(int n, int m) {
        return (long long) m*n / 2;
    }
};