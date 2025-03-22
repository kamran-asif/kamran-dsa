class Solution {
public://bht acha swal ha bhai so much learning
    int maxProfit(int k, vector<int>& prices) {
 
        int n = prices.size();
        if (k == 0 || n <= 1) return 0;

        // if k is large enough, use the infinite transactions approach
        if (2 * k >= n) {
            int res = 0;
            for (int i = 1; i < n; i++) { 
                if (prices[i] > prices[i - 1]) {
                    res += prices[i] - prices[i - 1];
                }
            }
            return res;
        }

        // dp initialization
        vector<int> dp(2 * k + 1, 0);
        dp[0] = -prices[0];
        for (int i = 1; i < 2 * k + 1; i++) {
            if (i % 2 == 0) dp[i] = INT_MIN;
            else dp[i] = 0;
        }

        // dp computation
        for (int i = 1; i < n; i++) { 
            for (int j = 0; j < 2 * k; j++) {
                if (j == 0) {
                    dp[j] = max(dp[j], -prices[i]); //1st buy
                } else if (j % 2 == 0) { // buy
                    dp[j] = max(dp[j], dp[j - 1] - prices[i]);
                } else { // sell
                    dp[j] = max(dp[j], dp[j - 1] + prices[i]);
                }
            }
        }
        return dp[2 * k - 1]; 
    }
};
