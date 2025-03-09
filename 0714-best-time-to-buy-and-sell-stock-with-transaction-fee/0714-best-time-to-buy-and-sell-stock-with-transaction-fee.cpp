class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        if(n == 0) return 0;
        
        // dp[i][0] -> Maximum profit if no stock is held on day i
        // dp[i][1] -> Maximum profit if a stock is held on day i
        vector<vector<int>> dp(n, vector<int>(2, 0));
        
        // Base case
        dp[0][0] = 0;              // No stock on day 0
        dp[0][1] = -prices[0];     // Bought stock on day 0
        
        for(int i = 1; i < n; i++) {
            // Maximum profit without any stock today
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i] - fee);
            
            // Maximum profit if you are holding a stock today
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i]);
        }
        
        // The maximum profit will be when we do not have any stock on the last day
        return dp[n-1][0];
    }
};


