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

// class Solution {
// public:
//     vector<int> countBits(int n) {
//         vector<int> result(n+1);

//         for (int i = 0; i <= n; i++) {
//             result[i] = __builtin_popcount(i);
//         }

//         return result;
//     }
// };

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result(n+1);

        result[0] = 0;

        for (int i = 1; i <= n; i++) {
            if(i % 2 != 0) {
                result[i] = result[i/2] + 1;
            } else {
                result[i] = result[i/2];
            }
        }

        return result;
    }
};