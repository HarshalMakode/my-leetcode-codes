class Solution {
    public String findDifferentBinaryString(String[] nums) {
        String result = "";

        for(int i = 0; i < nums.length; i++) {
            char ch = nums[i].charAt(i);
            
            if(ch == '0') {
                result += '1';
            } else {
                result += '0';
            }
        }

        return result;
    }
}