class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxD = 0;
        int maxArea = 0;
        for(int i = 0; i < dimensions.size(); i++) {
            int l = dimensions[i][0];
            int b = dimensions[i][1];
            int d = l*l + b*b;
            cout << d;
            int area = l * b;
            if(d > maxD) {
                maxArea = area;
                maxD  = d;
            } else if( d == maxD) {
                maxArea = max(maxArea, area);
            }
        }
        return maxArea;
    }
};