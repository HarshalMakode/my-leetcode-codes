// class Solution {
//     public long subArrayRanges(int[] nums) {
//         int n = nums.length;
//         long sum = 0;

//         for(int i = 0; i < n; i++) {
//             int mini = nums[i];
//             int maxi = nums[i];

//             for(int j = i; j < n; j++) {
//                 mini = Math.min(mini, nums[j]);
//                 maxi = Math.max(maxi, nums[j]);

//                 sum += maxi - mini;
//             }
//         }

//         return sum;
//     }
// }


class Solution {
    int n;

    public int[] nextGreaterEle(int[] arr) {
        
        Stack<Integer> st = new Stack<>();
        int[] result = new int[n];

        for(int i = n - 1; i >= 0; i--) {

            while(!st.isEmpty() && arr[st.peek()] <= arr[i]) {
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

    public int[] previousGreaterEleEqual(int[] arr) {
        
        Stack<Integer> st = new Stack<>();
        int[] result = new int[n];

        for(int i = 0; i < n; i++) {

            while(!st.isEmpty() && arr[st.peek()] < arr[i]) {
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

    public long sumMin(int[] arr) {
        long sum = 0;

        int[] nse = nextSmallerEle(arr);
        int[] pse = previousSmallerEleEqual(arr);
        
        for(int i = 0; i < n; i++) {
            int left = i - pse[i];
            int right = nse[i] - i;

            sum += (left*right*1L*arr[i]);
        }

        return sum;
    }

    public long sumMax(int[] arr) {
        long sum = 0;

        int[] nse = nextGreaterEle(arr);
        int[] pse = previousGreaterEleEqual(arr);
        
        for(int i = 0; i < n; i++) {
            int left = i - pse[i];
            int right = nse[i] - i;

            sum += (left*right*1L*arr[i]);
        }

        return sum;
    }

    public long subArrayRanges(int[] nums) {
        n = nums.length;
        return sumMax(nums) - sumMin(nums);
    }
}