class Solution {
public:
    bool checkOnesSegment(string s) {
        int segment = 0;

        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '1') {
                if(i == 0 || s[i-1] == '0') {
                    segment++;
                }
            }
        }

        if(segment <= 1) {
            return true;
        }

        return false;
    }
};