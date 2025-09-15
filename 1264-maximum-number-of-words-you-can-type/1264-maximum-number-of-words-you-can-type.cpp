class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        bool mp[26];

        for(char &ch: brokenLetters) {
            mp[ch-'a'] = true;
        }

        int result = 0;

        bool cantype = true;

        for(char &ch: text) {
            if(ch == ' ') {
                if(cantype) {
                    result++;
                }
                cantype = true;
            } else if(mp[ch-'a'] == true) {
                cantype = false;
            }
        }

        if(cantype) {
            result++;
        }

        return result;

    }
};