class Solution {
    public long maximumHappinessSum(int[] happiness, int k) {
        Arrays.sort(happiness);
        int n = happiness.length - 1; 
        long curr = 0;
        int a = 0;
        if(k == 1) {
            return (long)happiness[n];
        }

        for(int i = n; i >= 0; i--) {
            if(happiness[i] - a < 0 || k == 0) {
                break;
            }
            curr += happiness[i] - a;
            System.out.println(curr);
            a++;
            k--;

        }
        return curr;
    }
}