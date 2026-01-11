class Solution {
public:
    int lHist(vector<int>& heights) {
        stack<int> s;
        int maxArea = 0;
        int n = heights.size();

        for(int i = 0; i <= n; i++) {
            int curr = (i == n ? 0 : heights[i]);

            while(!s.empty() && curr < heights[s.top()]) {
                int h = heights[s.top()];
                s.pop();
                int w = s.empty() ? i : i - s.top() - 1;
                maxArea = max(maxArea, h * w);
            }
            s.push(i);
        }
        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;

        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> height(n, 0);
        int maxArea = 0;
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == '1')
                    height[j] += 1;
                else
                    height[j] = 0;
            }
            maxArea = max(maxArea, lHist(height));
        }
        return maxArea;
    }
};