// class Solution {
//     int M = (int) 1e9+7;

//     public int sumSubarrayMins(int[] arr) {
//         int sum = 0;
//         int n = arr.length;

//         for(int i = 0; i < n ; i++) {
//             int mini = arr[i];
//             for(int j = i; j < n; j++) {
//                 mini = Math.min(mini, arr[j]);
//                 sum = (sum + mini) % M;
//             }
//         }

//         return sum;
//     }
// }

class Solution {
    int M = (int) 1e9+7;
    int n;

    public int[] nextSmallerEle(int[] arr) {
        
        Stack<Integer> st = new Stack<>();
        int[] result = new int[n];

        for(int i = n - 1; i >= 0; i--) {

            while(!st.isEmpty() && arr[st.peek()] >= arr[i]) {
                st.pop();
            }

            if(st.isEmpty()) {
                result[i] = n;
            } else {
                result[i] = st.peek();
            }

            st.push(i);
        }

        return result;
    }

    public int[] previousSmallerEleEqual(int[] arr) {
        
        Stack<Integer> st = new Stack<>();
        int[] result = new int[n];

        for(int i = 0; i < n; i++) {

            while(!st.isEmpty() && arr[st.peek()] > arr[i]) {
                st.pop();
            }

            if(st.isEmpty()) {
                result[i] = -1;
            } else {
                result[i] = st.peek();
            }

            st.push(i);
        }

        return result;
    }

    public int sumSubarrayMins(int[] arr) {
        long sum = 0;
        n = arr.length;
        
        int[] nse = nextSmallerEle(arr);
        int[] pse = previousSmallerEleEqual(arr);
        
        for(int i = 0; i < n; i++) {
            int left = i - pse[i];
            int right = nse[i] - i;

            sum = (sum + (left*right*1L*arr[i])%M)%M;
        }

        return (int) sum;
    }
}