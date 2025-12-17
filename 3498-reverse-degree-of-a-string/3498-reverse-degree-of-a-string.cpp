class Solution {
public:
    int reverseDegree(string s) {
        int sum = 0;
        for(int i = 0; i < s.length(); i++) {
            int rev =  26 - (s[i] - 'a');
            int pro = rev * (i+1);
            sum = sum + pro;
        } 
        return sum;
    }
};