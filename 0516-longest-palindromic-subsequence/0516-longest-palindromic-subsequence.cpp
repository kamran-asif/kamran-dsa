class Solution {
public:
int lcs(string s1, string s2) {
 int n = s1.size();
    int m = s2.size();
     //2d dp array bnao length store krne liy
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    //1st coloumn ko 0 s initialise kro
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }
    for (int i = 0; i <= m; i++) {
        dp[0][i] = 0;
    }
    //dp arrray ko bhro
    for (int ind1 = 1; ind1 <= n; ind1++) {
        for (int ind2 = 1; ind2 <= m; ind2++) {
            if (s1[ind1 - 1] == s2[ind2 - 1])
                dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
            else
                dp[ind1][ind2] = max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]);
        }
    }
    //dp[n][m]length store krega lcs ka
    return dp[n][m];
}
    int longestPalindromeSubseq(string s) {
 string t = s;
    reverse(s.begin(), s.end());
    //lcs fn ko call kro take length nkal ske lcs ka 
    return lcs(s, t);
}
};