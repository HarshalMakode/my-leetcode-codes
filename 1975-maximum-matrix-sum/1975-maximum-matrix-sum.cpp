class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long result = 0;
        int minNegative = INT_MAX;
        int countNegative = 0;

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                int val = matrix[i][j];
                
                result += abs(val);
                
                if (val < 0) {
                    countNegative++;
                }        
                minNegative = min(minNegative, abs(val));  
            }
        }

        if(countNegative % 2 != 0) {
            return result - (2LL * minNegative);
        }

        return result;
    }
};