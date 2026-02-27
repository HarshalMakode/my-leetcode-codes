// class Solution {
// public:
//     int minimumDeletions(string s) {
//         if (s.empty()) return 0;

//         stack<int> st;
//         int count = 0;

//         st.push(s[0]);

//         for(int i = 1; i < s.length(); i++) {
//             if(!st.empty() && s[i] == 'a' && st.top() == 'b') {
//                 st.pop();
//                 count++;
//             } else 
//                 st.push(s[i]);
//         }

//         return count;
//     }
// };


class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        int right_a = 0;

        for(int i = 0; i < n; i++) {
            if(s[i] == 'a') {
                right_a++;
            }
        }

        int count = INT_MAX;
        int left_b = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == 'a') {
                right_a--;
            }
            
            count = min(count, right_a + left_b);

            if(s[i] == 'b') {
                left_b++;
            }
        }

        return count;
    }
};