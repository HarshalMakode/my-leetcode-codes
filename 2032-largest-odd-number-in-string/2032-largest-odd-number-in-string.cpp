// class Solution {
// public:
//     string largestOddNumber(string num) {
//         string result = "";
//         int n = num.length();

//         for(int i = 1; i <= n; i++) {
//             if((num[n-i] - '0') % 2 != 0) {
//                 return num.substr(0, n- i + 1);
//             }
//             // int digit = num[i] - '0';
//             // if(digit % 2 != 0) {
//             //     result += num[i];
//             // }
//         }

//         return result;
//     }
// };


class Solution {
public:
    string largestOddNumber(string num) {
        int n= num.length();
        for(int i=n-1;i>=0;i--){
           if((num[i]-'0')%2 != 0)
           {
            return num.substr(0,i+1);
           }
        }
        return "";
    }
};