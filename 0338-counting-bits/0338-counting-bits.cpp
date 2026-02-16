// class Solution {
// public:
//     vector<int> countBits(int n) {
//         vector<int> result(n+1);

//         for (int i = 0; i <= n; i++) {
//             int count = 0;
//             int x = i;

//             while (x > 1) {
//                 count += x & 1;
//                 x = x >> 1;
//             }

//             if (x == 1)
//                 count++;

//             result[i] = count;
//         }

//         return result;
//     }
// };   O(nlogn)

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result(n+1);

        for (int i = 0; i <= n; i++) {
            result[i] = __builtin_popcount(i);
        }

        return result;
    }
};