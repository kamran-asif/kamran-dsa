class Solution {
public:
    int rob(vector<int>& nums) {
       int n=nums.size();
       if(n==0)return 0;
       if(n==1)return nums[0];
       vector<int>dp(n,0);
       for(int i=0;i<n;i++){
        int pick=nums[i];
        if(i>1)
        pick=pick+dp[i-2];
        int nonpick=dp[i-1];
        dp[i]=max(pick,nonpick);
       } 
       return dp[n-1];
    }
};