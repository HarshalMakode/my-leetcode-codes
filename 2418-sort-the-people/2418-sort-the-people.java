class Solution {
    public String[] sortPeople(String[] names, int[] heights) {

        int n = heights.length;

        Map<Integer, String> mp = new TreeMap<>(Collections.reverseOrder());

        for(int i = 0; i < n; i++) {
            mp.put(heights[i], names[i]);
        }

        return mp.values().toArray(new String[0]);
    }
}