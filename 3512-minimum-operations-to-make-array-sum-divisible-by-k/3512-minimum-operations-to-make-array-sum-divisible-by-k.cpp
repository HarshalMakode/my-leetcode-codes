// class Solution {
// public:
//     int minOperations(vector<int>& nums, int k) {
//         int sum = 0;
//         int count = 0;

//         for(int i = 0; i < nums.size(); i++) {
//             sum = sum + nums[i];
//         }

//         if(sum % k == 0) {
//             return 0;
//         }

//         while(sum > 0) {
//             sum--;
//             count++;
//             if(sum % k == 0) {
//                 return count;
//             }
//         }

//         return count;
//     }
// };

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int sum = 0;

        int n = nums.size();

        for(int i = 0; i < n; i++){
            sum = sum + nums[i];
        }
        int remember = sum % k;
        return remember;
    }
};