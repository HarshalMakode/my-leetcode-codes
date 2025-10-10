class Solution {
public:

    bool stringok(string str) {
        for(int i = 0; i < str.length() - 1; i++) {
            if(str[i] != '1' && str[i+1] != '1') return false;
        }
        return true;
    }

    void solve(vector<string>& result, string curr, int n) {
        
        if(curr.length() == n) {
            if(stringok(curr))
            result.push_back(curr);
            return;
        }
        
        solve(result, curr + '0', n);
        
        solve(result, curr + '1', n);
        
    }

    vector<string> validStrings(int n) {
        vector<string> str;
        solve(str, "", n);
        return str;
    }
};