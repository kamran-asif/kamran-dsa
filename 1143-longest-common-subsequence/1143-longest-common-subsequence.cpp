class Solution {
public:
int lcsUtil(int i,int j,string &text1,string &text2,vector<vector<int>>&dp){//pass dp{
    if(i<0||j<0)return 0;
     //chek kro agr visit hogaya hai to
    if(dp[i][j]!=-1)
    return dp[i][j];
    if(text1[i]==text2[j] ){
    return dp[i][j] = 1 + lcsUtil(i - 1, j - 1, text1, text2, dp);//pass dp or isko store krlo dp[i][j]me 
     } else{ 
     return dp[i][j] = max(lcsUtil(text1,text2,i,j-1, dp), lcsUtil(text1,text2,i-1,j,dp));
    }
}
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        //memoization k dp initialise
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(n-1,m-1,text1,text2,dp)//pass dp
    }
};