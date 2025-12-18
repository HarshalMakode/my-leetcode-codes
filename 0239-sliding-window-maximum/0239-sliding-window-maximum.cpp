////Brute force

// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         vector<int> result;
        
//         for(int i = 0; i < nums.size() - k + 1; i++) {
//             int l = i;
//             int r = l + k - 1;
//             int maxi = INT_MIN;
            
//             while(l <= r && r < nums.size()) {
//                 maxi = max(maxi, nums[l]);
//                 l++;
//             }

//             result.push_back(maxi);
//         }

//         return result;
//     }
// };

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> result;
        
        //1st window
        for(int i = 0; i < k; i++) {
            //removing smaller value
            while(dq.size() > 0 && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        
        for(int i = k; i < nums.size(); i++) {
            result.push_back(nums[dq.front()]);

            //remove not part of curr window
            while(dq.size() > 0 && dq.front() <= i-k) {
                dq.pop_front();
            }

            while(dq.size() > 0 && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }

            dq.push_back(i);
        }

        result.push_back(nums[dq.front()]);

        return result;
    }
};