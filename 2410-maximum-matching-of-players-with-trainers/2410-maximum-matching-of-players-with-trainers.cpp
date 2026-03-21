class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& g, vector<int>& s) {
        sort(begin(g), end(g));
        sort(begin(s), end(s));
        int m = g.size();
        int n = s.size();
        int l = 0;
        int r = 0;

        while(l < m && r < n) {
            if(g[l] <= s[r]) {
                l++;
            } 
            r++;
        }

        return l;
    }
};