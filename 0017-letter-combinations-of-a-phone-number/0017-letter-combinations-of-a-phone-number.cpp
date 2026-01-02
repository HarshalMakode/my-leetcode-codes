class Solution {
public:

    map<char, string> mp = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };

    void solve(string digits, int i, string str, vector<string>& res) {
        if(i == digits.size()) {
            res.push_back(str);
            return;
        }

        string str1 = mp[digits[i]];

        for(int indx = 0; indx < str1.size(); indx++) {
            str += str1[indx];
            solve(digits, i+1, str, res); 
            str.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> res;
        string str;
        solve(digits, 0, str, res);
        return res;
    }
};