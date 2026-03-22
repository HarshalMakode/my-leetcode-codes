class Solution {
public:
    void reverse(vector<int>& arr) {
        int left = 0;
        int right = arr.size() - 1;
        while (left < right) {
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }

    void rotate(vector<vector<int>>& matrix) {

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = i + 1; j < matrix.size(); j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for (int i = 0; i < matrix.size(); i++) {
            reverse(matrix[i]);
        }
    }

    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        for(int i = 0; i < 4; i++) {
            if(mat == target) {
                return true;
            }
            rotate(mat);
        }
        return false;
    }
};