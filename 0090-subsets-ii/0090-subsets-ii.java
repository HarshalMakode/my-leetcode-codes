class Solution {

    private void solve(int[] nums, int i, List<List<Integer>> res, List<Integer> subset) {
        if(i == nums.length) {
            res.add(new ArrayList<>(subset));
            return;
        }

        subset.add(nums[i]);
        solve(nums, i+1, res, subset);
        subset.remove(subset.size() - 1);

        int index = i+1;

        while(index < nums.length && nums[index] == nums[index-1]) 
            index++;

        solve(nums, index, res, subset);

    }

    public List<List<Integer>> subsetsWithDup(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        List<Integer> subset = new ArrayList<>();
        Arrays.sort(nums);
        solve(nums, 0, res, subset);
        return res;
    }
}