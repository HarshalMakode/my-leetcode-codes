// class Solution {
//     public int lengthOfLongestSubstring(String s) {
//         int result = 0;
//         int n = s.length();

//         for(int i = 0; i < n; i++) {
//             HashSet<Character> set = new HashSet<>();
//             int count = 0;
//             int j = i;
//             while(j < n && !set.contains(s.charAt(j))) {
//                 set.add(s.charAt(j));
//                 count++;
//                 j++;
//             }

//             result = Math.max(count, result);
//         }

//         return result;
//     }
// }


class Solution {
    public int lengthOfLongestSubstring(String s) {
        int result = 0;
        int n = s.length();
        HashSet<Character> set = new HashSet<>();
        int j = 0;

        for(int i = 0; i < n; i++) {
            while(set.contains(s.charAt(i))) {
                set.remove(s.charAt(j));
                j++;
            }

            set.add(s.charAt(i));

            result = Math.max(i-j+1, result);
        }

        return result;
    }
}