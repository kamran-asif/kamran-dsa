class Solution {
public://dp with bit manuplation tough one
    vector<int> countBits(int n) {
        vector<int>dp(n+1,0);
        for(int i=0;i<=n;i++){
         dp[i]=dp[i>>1]+(i&1);// dp[i/2]+(i%2)
        }
        return dp;
    }
};