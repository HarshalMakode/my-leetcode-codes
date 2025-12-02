// class Solution {
// public:
//     int maxDistinct(string s) {
        
//         unordered_map<char, int> mp;

//         for(int i = 0; i < s.length(); i++) {
//             mp[s[i]]++;
//         }

//         return mp.size();
//     }
// };

// class Solution {
// public:
//     int maxDistinct(string s) {
        
//         bool seen[256] = {false};
//         int count = 0;

//         for(char c : s) {
//             if(!seen[c]) {
//                 seen[c] = true;
//                 count++;
//             }
//         }

//         return count;
//     }
// };

class Solution {
public:
    int maxDistinct(string s) {
        unordered_set<char> st(s.begin(), s.end());
        return st.size();
    }
};