class Solution {
    public int maxProfit(int[] prices) {
        int minValue = Integer.MAX_VALUE;
        int maxProfit = 0;
        int profit = 0;

        for(int i = 0; i < prices.length; i++) {
            if(prices[i] < minValue) {
                minValue = prices[i]; 
            }
            
            if((i != prices.length-1)) 
                profit = prices[i+1] - minValue; 

            if(profit > maxProfit) {
                maxProfit = profit; 
            }
        }

        return maxProfit;
    }
}