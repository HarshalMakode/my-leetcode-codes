class Solution {
    public int minFlips(String s) {

        int n = s.length();

        s = s + s;

        StringBuilder s1 = new StringBuilder();
        StringBuilder s2 = new StringBuilder();

        for(int i = 0; i < 2 * n; i++) {
            if(i % 2 == 1){
                s1.append('0');
                s2.append('1');
            } 
            else{
                s1.append('1');
                s2.append('0');
            }
        }

        int result = Integer.MAX_VALUE;
        int flip1 = 0;
        int flip2 = 0;

        int i = 0;
        int j = 0;

        while(j < 2 * n) {

            if(s.charAt(j) != s1.charAt(j)) {
                flip1++;
            }

            if(s.charAt(j) != s2.charAt(j)) {
                flip2++;
            }

            if(j - i + 1 > n) {   // shrink window
                if(s.charAt(i) != s1.charAt(i)) {
                    flip1--;
                }

                if(s.charAt(i) != s2.charAt(i)) {
                    flip2--;
                }

                i++;
            }

            if(j - i + 1 == n) {
                result = Math.min(result, Math.min(flip1, flip2));
            }

            j++;
        }

        return result;
    }
}