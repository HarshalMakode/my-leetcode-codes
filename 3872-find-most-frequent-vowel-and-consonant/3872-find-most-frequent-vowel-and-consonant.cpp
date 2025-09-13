class Solution {
public:
    int maxFreqSum(string s) {
        int maxV = 0;
        int maxC = 0;
        int arr[26] = {0};

        for(auto &i: s) {
            arr[i-'a']++;

            if(string("aeiou").find(i) != string::npos) {
                maxV = max(maxV, arr[i-'a']);
            } else {
                maxC = max(maxC, arr[i-'a']);
            }
        }
        return maxC + maxV;
    }
};