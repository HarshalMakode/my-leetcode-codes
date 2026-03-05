class Solution {
public:
    int minOperations(string s) {
        int count1 = 0;
        int count2 = 0;

        for (int i = 0; i < s.length(); i++) {

            if (i % 2) {
                if (s[i] != '1') {
                    count1++;
                }
            } else {
                if (s[i] != '0') {
                    count1++;
                }
            }

            if (i % 2) {
                if (s[i] != '0') {
                    count2++;
                }
            } else {
                if (s[i] != '1') {
                    count2++;
                }
            }
        }

        int count = min(count1, count2);

        return count;
    }
};