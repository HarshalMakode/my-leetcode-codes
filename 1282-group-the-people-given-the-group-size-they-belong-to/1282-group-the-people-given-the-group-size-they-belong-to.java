class Solution {
    public List<List<Integer>> groupThePeople(int[] groupSizes) {
        List<List<Integer>> result = new ArrayList<>();
        HashMap<Integer, List<Integer>> map = new HashMap<>();

        for (int i = 0; i < groupSizes.length; i++) {
            int size = groupSizes[i];

            if (!map.containsKey(size)) {
                map.put(size, new ArrayList<>());
            }

            map.get(size).add(i);

            if (map.get(size).size() == size) {
                result.add(map.get(size));
                map.remove(size);
            }

        }

        return result;
    }
}