class Solution {

    private void solve(int idx, int[] arr, int target, List<List<Integer>> result, List<Integer> ds) {
        if(idx == arr.length) {
            if(target == 0) {
                result.add(new ArrayList<>(ds));
            }
            return;
        }

        if(arr[idx] <= target) {
            ds.add(arr[idx]);
            solve(idx, arr, target - arr[idx], result, ds);
            ds.remove(ds.size() - 1);
        }
        solve(idx + 1, arr, target, result, ds);
        
    }

    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> result = new ArrayList<>();
        solve(0, candidates, target, result, new ArrayList<>());
        return result;
    }
}