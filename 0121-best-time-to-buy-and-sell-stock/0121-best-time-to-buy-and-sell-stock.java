class Solution {
    public int maxProfit(int[] prices) {
        int minValue = prices[0];
        int maxProfit = 0;

        for(int i = 1; i < prices.length; i++) {
            if(prices[i] < minValue) {
                minValue = prices[i]; 
            } 
            int profit = prices[i] - minValue; 
            if(profit > maxProfit) {
                maxProfit = profit; 
            }
        }

        return maxProfit;
    }
}