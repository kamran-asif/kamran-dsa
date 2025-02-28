#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.size(), n = str2.size();
        
        // Step 1: Compute the Longest Common Subsequence (LCS) using Dynamic Programming
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (str1[i - 1] == str2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1]; // Match case
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); // Choose max from previous states
            }
        }

        // Step 2: Build the Shortest Common Supersequence (SCS) using backtracking
        string scs = "";
        int i = m, j = n;
        
        while (i > 0 && j > 0) {
            if (str1[i - 1] == str2[j - 1]) { 
                scs += str1[i - 1]; // If characters match, add once
                i--; j--;
            } 
            else if (dp[i - 1][j] > dp[i][j - 1]) { 
                scs += str1[i - 1]; // Take from str1
                i--;
            } 
            else { 
                scs += str2[j - 1]; // Take from str2
                j--;
            }
        }

        // Append remaining characters from str1 or str2
        while (i > 0) {
            scs += str1[i - 1];
            i--;
        }
        while (j > 0) {
            scs += str2[j - 1];
            j--;
        }

        // Reverse since we built the string backwards
        reverse(scs.begin(), scs.end());
        return scs;
    }
};
