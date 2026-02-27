class Solution {
public:
    int minimumDeletions(string s) {
        if (s.empty()) return 0;

        stack<int> st;
        int count = 0;

        st.push(s[0]);

        for(int i = 1; i < s.length(); i++) {
            if(!st.empty() && s[i] == 'a' && st.top() == 'b') {
                st.pop();
                count++;
            } else 
                st.push(s[i]);
        }

        return count;
    }
};