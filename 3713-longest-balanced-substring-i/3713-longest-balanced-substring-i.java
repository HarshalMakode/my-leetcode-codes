class Solution {

    public boolean checkBalanced(int[] freq) {
        int common = 0;
        for(int i = 0; i < 26; i++) {
            if(freq[i] == 0) continue;
            if(common == 0) common = freq[i];
            else if(freq[i] != common) return false;
        }
        return true;
    }

    public int longestBalanced(String s) {
        int maxL = 0;
        for(int i = 0; i < s.length(); i++) {
            int[] freq = new int[26];
            for(int j = i; j < s.length(); j++) {
                freq[s.charAt(j) - 'a']++;
                if(checkBalanced(freq)) {
                    maxL = Math.max(maxL, j - i + 1);
                }
            }
        }

        return maxL;
    }
}