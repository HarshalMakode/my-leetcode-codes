class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        vector<int> result(n);

        for(int i = 2*n-1; i >= 0; i--) {
            while(!st.empty() && st.top() <= nums[i%n]) {
                st.pop();
            }
            if(st.empty()) {
                result[i%n] = -1;
            } else {
                result[i%n] = st.top();
            }
            st.push(nums[i%n]);
        }

        return result;
    }
};