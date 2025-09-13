class Solution {
public:
    int myAtoi(string s) {
        string str = "";
        int i = 0;

        while (i < s.length() && s[i] == ' ') {
            i++;
        }

        if (i < s.length() && (s[i] == '-' || s[i] == '+')) {
            str += s[i];
            i++;
        }

        while (i < s.length() && isdigit(s[i])) {
            str += s[i];
            i++;
        }

        if (str == "" || str == "-" || str == "+") return 0;

        try {
            return stoi(str);
        } catch (out_of_range&) {
            return (str[0] == '-') ? INT_MIN : INT_MAX;
        }
    }
};
