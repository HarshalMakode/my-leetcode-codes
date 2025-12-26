// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         int maxLength = 0;

//         unordered_map<char, int> mp;

//         int left = 0;
//         int right = 0;

//         int n = s.length();

//         int count = 0;

//         while(right < n) {
//             if(mp.find(s[right]) == mp.end()) {
//                 mp[s[right]]++;
//                 count++;
//                 right++;
//             } else {
//                 count = 0;
//                 left++;
//                 right = left;
//                 mp.clear();
//             }
//             maxLength = max(maxLength, count);
//         }

//         return maxLength;
//     }
// };


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLength = 0;

        int n = s.length();

        vector<int> mp(256, -1);

        int l = 0;
        int r = 0; 

        while(r < n) {
            if(mp[s[r]] != -1) {
                if(mp[s[r]] >= l) {
                    l = mp[s[r]] + 1;
                }
            }
            int length = r - l + 1;
            maxLength = max(maxLength, length);

            mp[s[r]] = r;
            r++;
        }
                                   
        return maxLength;
    }
};