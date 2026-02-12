class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        int i = 0;
        while(i < s.length()) {
            if(s[i] == ')' || s[i] == ']' || s[i] == '}') {
                if(st.empty()) return false;
                if(st.top() == '(' && s[i] == ')') {
                    st.pop();
                } else if(st.top() == '{' && s[i] == '}') {
                    st.pop();
                } else if(st.top() == '[' && s[i] == ']') {
                    st.pop();
                } else {
                    st.push(s[i]);
                }
                i++;
            } else {
                st.push(s[i]);
                i++;
            }
        }
        return st.empty();
    }
};