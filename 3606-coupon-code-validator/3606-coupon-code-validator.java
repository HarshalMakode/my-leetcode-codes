class Solution {
    public List<String> validateCoupons(String[] code, String[] businessLine, boolean[] isActive) {

        List<int[]> valid = new ArrayList<>();
        List<String> result = new ArrayList<>();

        Map<String, Integer> order = new HashMap<>();
        order.put("electronics", 0);
        order.put("grocery", 1);
        order.put("pharmacy", 2);
        order.put("restaurant", 3);

        for (int i = 0; i < code.length; i++) {
            if (code[i].matches("^[a-zA-Z0-9_]+$") &&
                order.containsKey(businessLine[i]) &&
                isActive[i]) {

                valid.add(new int[]{i});
            }
        }

        // custom sorting
        Collections.sort(valid, (a, b) -> {
            int idx1 = a[0];
            int idx2 = b[0];

            int cmp = order.get(businessLine[idx1]) - order.get(businessLine[idx2]);
            if (cmp != 0) return cmp;

            return code[idx1].compareTo(code[idx2]);
        });

        // collect only codes
        for (int[] arr : valid) {
            result.add(code[arr[0]]);
        }

        return result;
    }
}
