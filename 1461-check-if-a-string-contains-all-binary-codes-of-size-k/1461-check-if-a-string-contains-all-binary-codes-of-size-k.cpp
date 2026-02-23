class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if (k > s.size()) return false;
        set<string> sub;

        for(int i = 0; i <= s.size() - k; i++) {
            sub.insert(s.substr(i, k));
        }

        return sub.size() == pow(2, k);
    }
};