class Solution {
    public double findMaxAverage(int[] arr, int k) {
        int sum = 0;
        int n = arr.length;
        
        for(int i = 0; i < k; i++) {
            sum += arr[i];
        }
        
        double result = sum;
        
        int left = 0;
        int right = k;
        
        while(right < n) {
            sum -= arr[left];
            left++;
            sum += arr[right];
            right++;
            
            if(result < sum) {
                result = sum;
            }
        }
        
        return result/k;
    }
}