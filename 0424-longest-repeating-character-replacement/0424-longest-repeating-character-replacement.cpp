class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int r = 0;
        int l = 0;
        int maxi = 0;
        int maxf = 0;
        unordered_map<char, int> mp;

        while(r < n) {
            mp[s[r]]++;

            maxf = max(maxf, mp[s[r]]);

            while((r - l + 1) - maxf > k) {
                mp[s[l]]--;
                l++;
            }

            maxi = max(maxi, r -l + 1);
            
            r++;
        }

        return maxi;
    }
};