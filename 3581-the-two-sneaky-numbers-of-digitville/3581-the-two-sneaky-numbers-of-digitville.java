class Solution {
    public int[] getSneakyNumbers(int[] nums) {
        Map<Integer, ArrayList<Integer>> mp = new HashMap<>();
        ArrayList<Integer> result = new ArrayList<>();

        for(int i = 0; i < nums.length; i++) {
            mp.putIfAbsent(nums[i], new ArrayList<>());
            mp.get(nums[i]).add(i);
        }

        for (Map.Entry<Integer, ArrayList<Integer>> entry : mp.entrySet()) {
            
            ArrayList<Integer> a = entry.getValue();

            if(a.size() == 2) {
                result.add(entry.getKey());
            }

        }

        int[] ans = new int[result.size()];
        for (int i = 0; i < result.size(); i++) {
            ans[i] = result.get(i);
        }

        return ans;
    }
}