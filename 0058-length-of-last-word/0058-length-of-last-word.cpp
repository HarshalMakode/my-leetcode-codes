class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 0;
        int i = 0;

        for(i = s.length() - 1; i >= 0 ; i--) {
            if(s[i] == ' ') {
                continue;
            } else {
                break;
            }
        }

        cout << s.length();

        cout << i;

        for(int j = i; j >= 0 ; j--) {
            if(s[j] == ' ') {
                break;
            } else {
                count++;
            }
        }

        return count;
    }
};