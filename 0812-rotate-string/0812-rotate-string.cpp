// class Solution {
// public:
//     bool rotateString(string s, string goal) {

//         if(s.length() != goal.length()) {
//             return false;
//         }

//         int j = 0;
//         char ch = s[0];
//         bool valid = true;

//         int n = goal.length();
//         for(j = 0; j < n; j++) {
//             if(goal[j] == ch) {
//                 break;
//             }
//         }

//         cout << j;

//         for(int i = 0; i < s.length(); i++) {
//             cout << s[i];
//             cout << goal[j%n];
//             if(s[i] != goal[j%n]) {
//                 valid = false;
//                 break;
//             }
//             j++;
//         }

//         return valid;
//     }
// };



// class Solution {
// public:
//     bool rotateString(string s, string goal) {
//         for(int i = 0; i < s.length(); i++) {
//             rotate(s.begin(), s.begin()+1, s.end());
//             if(s == goal) {
//                 return true;
//             }
//         }
//         return false;
//     }
// };


class Solution {
public:
    bool rotateString(string s, string goal) {

        if(s.length() != goal.length()) {
            return false;
        }
        
        if((s+s).find(goal) != string::npos)
            return true; 

        return false;
    }
};