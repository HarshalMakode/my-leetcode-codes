class Solution {
    public boolean isSubsequence(String s, String t) {

        if(t.length()<s.length()){
            return false;
        }

        int i = 0, j = 0;

        while (i < s.length() && j < t.length()) {
            if (s.charAt(i) == t.charAt(j)) {
                i++;
            }
            j++;
        }

        boolean isSub = (i == s.length());
        return isSub;
    }
}