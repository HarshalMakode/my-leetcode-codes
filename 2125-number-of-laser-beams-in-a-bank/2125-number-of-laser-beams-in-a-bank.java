class Solution {
    public int numberOfBeams(String[] bank) {
        int result = 0;
        int prev = 0;
        for (int i = 0; i < bank.length; i++) {
            int light = 0;
            for (int j = 0; j < bank[i].length(); j++) {
                if (bank[i].charAt(j) == '1') {
                    light++;
                }
            }
            if (light == 0) {
                continue;
            }
            if (prev != 0) {
                result += prev * light;
            }
            prev = light;
        }
        return result;
    }
}