class Solution {
public:
    int integerBreak(int n) {
     vector<int>dp(n+1,0);
     dp[2]=1;//bse cse
     for(int i=3;i<=n;i++){
           for(int j=1;j<i;j++){
            dp[i]=max(dp[i],max(j*(i-j),j*dp[i-j]));
           }
     }
     return dp[n];   
    }
};