class Solution {
    public int bestClosingTime(String customers) {
        int countY = 0;
        int countN = 0;
        int penalty = 0;
        int index = 0;

        for(int i = 0; i < customers.length(); i++) {
            if(customers.charAt(i) == 'Y') {
                countY++;
            }
        }

        penalty = countY;

        for(int i =0; i < customers.length(); i++) {
            if(customers.charAt(i) == 'Y') {
                countY--;
            } else if(customers.charAt(i) == 'N') {
                countN++;
            }

            int res = countY + countN;
            if(res < penalty) {
                penalty = res;
                index = i+1;
            }
        }


        return index;
    }
}