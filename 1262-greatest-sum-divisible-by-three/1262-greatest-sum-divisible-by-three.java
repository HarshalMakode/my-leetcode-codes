class Solution {
    public int maxSumDivThree(int[] nums) {
        int sum = 0;

        ArrayList<Integer> remain1 = new ArrayList<>();
        ArrayList<Integer> remain2 = new ArrayList<>();

        for (int num : nums) {
            sum = sum + num;

            if (num % 3 == 1) {
                remain1.add(num);
            } 
            else if (num % 3 == 2) {
                remain2.add(num);
            }
        }

        if (sum % 3 == 0) {
            return sum;
        }

        Collections.sort(remain1);
        Collections.sort(remain2);

        int res = 0;
        int remainder = sum % 3;

        int remove1 = Integer.MAX_VALUE;
        int remove2 = Integer.MAX_VALUE;

        if (remainder == 1) {

            if (remain1.size() >= 1) {
                remove1 = remain1.get(0);
            }

            if (remain2.size() >= 2) {
                remove2 = remain2.get(0) + remain2.get(1);
            }

            int remove = Math.min(remove1, remove2);
            if (remove != Integer.MAX_VALUE) {
                res = sum - remove;
            }
        }

        else if (remainder == 2) {

            if (remain2.size() >= 1) {
                remove1 = remain2.get(0);
            }

            if (remain1.size() >= 2) {
                remove2 = remain1.get(0) + remain1.get(1);
            }

            int remove = Math.min(remove1, remove2);
            if (remove != Integer.MAX_VALUE) {
                res = sum - remove;
            }
        }

        return res;
    }
}