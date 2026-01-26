class Solution {
    public List<List<Integer>> minimumAbsDifference(int[] arr) {
        List<List<Integer>> result = new ArrayList<>();
        Arrays.sort(arr);

        int mini = Integer.MAX_VALUE;
        


        for(int i = 0; i < arr.length - 1; i++) {
            mini = Math.min(mini, Math.abs(arr[i] - arr[i+1]));
        }

        for(int i = 0; i < arr.length - 1; i++) {
            List<Integer> temp = new ArrayList<>();
            if(mini == Math.abs(arr[i] - arr[i+1])) {
                temp.add(arr[i]);
                temp.add(arr[i+1]);
                result.add(temp);
            }
        }

        return result;

    }
}