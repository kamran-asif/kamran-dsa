#define ll unsigned long long
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<ll>> dp(coins.size()+1,vector<ll>(amount+1,0));
        for(int i=0;i<=coins.size();i++) dp[i][0]=1;
        for(ll i=1;i<coins.size()+1;i++)
        {
            for(ll j=1;j<amount+1;j++)
            {
                if(coins[i-1]<=j)
                {
                    dp[i][j]=dp[i][j-coins[i-1]]+dp[i-1][j];
                }
                else
                {
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[coins.size()][amount];
    }
};