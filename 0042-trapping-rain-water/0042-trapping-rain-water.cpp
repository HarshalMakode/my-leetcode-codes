class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> leftMax(n, 0);
        vector<int> rightMax(n, 0);

        int maxi = height[0];
        leftMax[0] = height[0];
        for(int i = 1; i < n; i++) {
            maxi = max(height[i], maxi);
            leftMax[i] = maxi;
        }

        maxi = height[n-1];
        rightMax[n-1] = height[n-1];
        for(int i = n-2; i >= 0; i--) {
            maxi = max(height[i], maxi);
            rightMax[i] = maxi;
        }

        int count = 0;
        for(int i = 0; i < n; i++) {
            count += min(leftMax[i], rightMax[i]) - height[i];
        }

        return count;
    }
};