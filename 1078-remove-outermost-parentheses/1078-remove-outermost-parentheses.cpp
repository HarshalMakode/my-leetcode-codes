class Solution {
public:
    string removeOuterParentheses(string s) {
        string result = "";
        int balance = 0;

        for (char c : s) {
            if (c == '(') {
                if (balance > 0) result += c;  // skip the very first '('
                balance++;
            } else {
                balance--;
                if (balance > 0) result += c;  // skip the very last ')'
            }
        }
        return result;
    }
};
