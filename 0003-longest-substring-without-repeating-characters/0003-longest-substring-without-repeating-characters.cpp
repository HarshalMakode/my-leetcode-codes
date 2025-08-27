class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLength = 0;

        unordered_map<char, int> mp;

        int left = 0;
        int right = 0;

        int n = s.length();

        int count = 0;

        while(right < n) {
            if(mp.find(s[right]) == mp.end()) {
                mp[s[right]]++;
                count++;
                right++;
            } else {
                count = 0;
                left++;
                right = left;
                mp.clear();
            }
            maxLength = max(maxLength, count);
        }

        return maxLength;
    }
};