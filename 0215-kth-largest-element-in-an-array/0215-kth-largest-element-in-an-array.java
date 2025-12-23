class Solution {
    public int findKthLargest(int[] nos, int k) {
        PriorityQueue<Integer> pq = new PriorityQueue<>();

        for(int i = 0; i < nos.length; i++) {
            pq.offer(nos[i]);
            if(pq.size() > k) {
                pq.poll(); //remove the extra element
            }
        }
        return pq.peek();

    }
}