// class Solution {
//     public List<Boolean> kidsWithCandies(int[] candies, int extraCandies) {
//         List<Boolean> result = new ArrayList<>();
//         int maxi = candies[0];

//         for(int i = 1; i< candies.length; i++) {
//             if(maxi < candies[i]) {
//                 maxi = candies[i];
//             }
//         }

//         for(int i = 0; i< candies.length; i++) {
//             if(maxi <= (candies[i] + extraCandies)) {
//                 result.add(true);
//             } else {
//                 result.add(false);
//             }
//         }

//         return result;
//     }
// }

class Solution {
    public List<Boolean> kidsWithCandies(int[] candies, int extraCandies) {
        int max = 0;
        List<Boolean> result = new ArrayList<>(candies.length);

        for (int i : candies) max = max < i ? i : max;

        for (int i : candies) result.add(i + extraCandies >= max);

        return result;
    }
}