class Solution {
    public int maximumWealth(int[][] accounts) {
        int result = 0;
        int maxWealth = 0;
        for(int i = 0; i < accounts.length; i++) {
            int wealth = 0;
            for(int j = 0; j < accounts[i].length; j++) {
                wealth = wealth + accounts[i][j];
            }

            maxWealth = Math.max( maxWealth ,wealth);

            // if(maxWealth < wealth)
            //     maxWealth = wealth;
            
        }
        return maxWealth;
    }
}