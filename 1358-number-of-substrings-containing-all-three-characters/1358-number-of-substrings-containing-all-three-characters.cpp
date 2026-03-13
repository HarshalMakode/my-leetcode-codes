class Solution {
public:
    int numberOfSubstrings(string s) {
        int count = 0;
        int n = s.length();
        vector<int> lastSeen = {-1, -1, -1};

        for(int i = 0; i < n; i++) {
            lastSeen[s[i] - 'a'] = i;
            if(lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1) {
                count = count + (1 + *min_element(begin(lastSeen), end(lastSeen)));
            }
        }

        return count;
    }
};