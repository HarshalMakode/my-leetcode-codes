// class Solution {
//     public long maximumHappinessSum(int[] happiness, int k) {
//         Arrays.sort(happiness);
//         int n = happiness.length - 1; 
//         long curr = 0;
//         int a = 0;
//         if(k == 1) {
//             return (long)happiness[n];
//         }

//         for(int i = n; i >= 0; i--) {
//             if(happiness[i] - a < 0 || k == 0) {
//                 break;
//             }
//             curr += happiness[i] - a;
//             a++;
//             k--;
//         }
//         return curr;
//     }
// }

class Solution {
    public long maximumHappinessSum(int[] happiness, int k) {
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        for (int h : happiness)
            pq.add(h);

        long sum = 0;
        int dec = 0;

        while (k-- > 0 && !pq.isEmpty()) {
            int top = pq.poll();
            if (top - dec <= 0)
                break;
            sum += top - dec;
            dec++;
        }

        return sum;

    }
}