// class Solution {
// public:
//     int myAtoi(string s) {
//         string str = "";
//         int i = 0;

//         while (i < s.length() && s[i] == ' ') {
//             i++;
//         }

//         if (i < s.length() && (s[i] == '-' || s[i] == '+')) {
//             str += s[i];
//             i++;
//         }

//         while (i < s.length() && isdigit(s[i])) {
//             str += s[i];
//             i++;
//         }

//         if (str == "" || str == "-" || str == "+") return 0;

//         try {
//             return stoi(str);
//         } catch (out_of_range&) {
//             return (str[0] == '-') ? INT_MIN : INT_MAX;
//         }
//     }
// };

class Solution {
    public:
    int myAtoi(string str) {
        long long result = 0; 
                       
        int i = 0;    
        int sign = 1;

        while(i < str.length() && str[i] == ' ') {
            i++;
        }             
        
        if (i < str.length() && str[i] == '-' || str[i] == '+') {
            sign = (str[i] == '-') ? -1 : 1;
            i++;
        }

        while (i < str.length() && str[i] >= '0' && str[i] <= '9') {
            result = result * 10 + str[i] - '0';

            if (sign * result >= INT_MAX) return INT_MAX;
            if (sign * result <= INT_MIN) return INT_MIN;
            
            i++;
        }
        return result * sign;
    }
};