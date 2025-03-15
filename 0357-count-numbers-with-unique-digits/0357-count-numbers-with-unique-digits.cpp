class Solution {
public:
    int countNumbersWithUniqueDigits(int n){
 
   
        if (n == 0) return 1;  
        vector<int> dp(n + 1, 0);
        dp[1] = 10;  
        
        int total = dp[1];
        int product = 9, availableDigits = 9;
        
        for (int i = 2; i <= n; i++) {
            product *= availableDigits;  // dp[i] = dp[i-1] * avilble chioices
            availableDigits--;  
            dp[i] = product;
            total += dp[i];  // sum all dp[i] valus
        }
        
        return total;
    }
};

