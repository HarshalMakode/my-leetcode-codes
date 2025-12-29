class Solution {
    public int[] findThePrefixCommonArray(int[] A, int[] B) {
        int n = A.length;
        int[] C = new int[n];

        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j <= i; j++) {
                boolean found = false;
                for (int k = 0; k <= i; k++) {
                    if (A[j] == B[k]) {
                        found = true;
                        break;
                    }
                }
                if (found) {
                    count++;
                }
            }

            C[i] = count;
        }

        return C;
    }
}
