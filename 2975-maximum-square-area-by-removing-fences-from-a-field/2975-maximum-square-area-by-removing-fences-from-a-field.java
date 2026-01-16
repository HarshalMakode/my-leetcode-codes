class Solution {
    int M = 1000000007;

    public int maximizeSquareArea(int m, int n, int[] hFences, int[] vFences) { 
        // Convert arrays to lists
        List<Integer> hList = new ArrayList<>();
        List<Integer> vList = new ArrayList<>();

        for (int x : hFences) hList.add(x);
        for (int x : vFences) vList.add(x);

        // Add borders
        hList.add(1);
        hList.add(m);

        vList.add(1);
        vList.add(n);

        // Sort
        Collections.sort(hList);
        Collections.sort(vList);

        // Store all possible widths
        Set<Integer> widths = new HashSet<>();

        for (int i = 0; i < vList.size(); i++) {
            for (int j = i + 1; j < vList.size(); j++) {
                widths.add(vList.get(j) - vList.get(i));
            }
        }

        int maxSide = 0;

        // Check heights
        for (int i = 0; i < hList.size(); i++) {
            for (int j = i + 1; j < hList.size(); j++) {
                int height = hList.get(j) - hList.get(i);
                if (widths.contains(height)) {
                    maxSide = Math.max(maxSide, height);
                }
            }
        }

        if (maxSide == 0) return -1;

        return (int) ((long) maxSide * maxSide % M);
    }
}
