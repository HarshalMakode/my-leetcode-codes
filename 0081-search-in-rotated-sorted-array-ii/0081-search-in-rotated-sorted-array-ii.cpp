class Solution {
public:
    bool search(vector<int>& nums, int target) {
        

        // set<int> s1(numss.begin(), numss.end());

        // vector<int> nums;

        // for(auto i: s1) {
        //     nums.push_back(i);
        // }

        int n = nums.size();
        int l = 0;
        int h = n - 1;

        while(l < h) {
            if(nums[l] == nums[l+1]) {
                l++;
            } else {
                break;
            }
        }

        while(l < h) {

            int m = l + (h - l) / 2;

            if(nums[m] > nums[h]) {
                l = (m+1);
            } else {
                h = m;
            }
        }

        int min = h;

        cout << min;

        l = 0;
        h = min - 1;

        bool result = false;

        while(l <= h) {
            int m = l + ( h - l) / 2;

            if(nums[m] == target) {
                result = true;
                break;
            } else if(nums[m] < target) {
                l = m+1;
            } else {
                h = m-1;
            }
        }

        if(result) {
            return result;
        }

        l = min;
        h = n -1;

        while(l <= h) {
            int m = l + ( h - l) / 2;

            if(nums[m] == target) {
                result = true;
                break;
            } else if(nums[m] < target) {
                l = m+1;
            } else {
                h = m-1;
            }
        }

        return result;
    }
};