class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(begin(g), end(g));
        sort(begin(s), end(s));
        int result = 0;
        int i = g.size() - 1;
        int j = s.size() - 1;

        while(i >= 0 && j >= 0) {
            if(g[i] > s[j]) {
                i--;
            } else if(g[i] <= s[j]) {
                result++;
                i--;
                j--;
            }
        }

        return result;
    }
};