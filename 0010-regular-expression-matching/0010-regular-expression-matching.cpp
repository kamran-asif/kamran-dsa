class Solution {
public://classic hard prblm try to solve again revisit code smjh ni aya pura
    bool isMatch(string s, string p) {
        return isMatchRecursive(s, p, 0, 0);
    }

private:
    // recursive approach
    bool isMatchRecursive(const string& text, const string& pattern, int pos1, int pos2) {
        if (pos2 == pattern.size()) {
            return pos1 == text.size();
        }

        bool firstMatch = (pos1 < text.size() && 
                          (text[pos1] == pattern[pos2] || pattern[pos2] == '.'));

        if (pos2 + 1 < pattern.size() && pattern[pos2 + 1] == '*') {
            return isMatchRecursive(text, pattern, pos1, pos2 + 2) || 
                   (firstMatch && isMatchRecursive(text, pattern, pos1 + 1, pos2));
        } else {
            return firstMatch && isMatchRecursive(text, pattern, pos1 + 1, pos2 + 1);
        }
    }

    // dynamic Programming approach
    bool isMatchDP(const string& text, const string& pattern) {
        int m = text.size(), n = pattern.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;

        // handle patterns like a*, a*b*, etc.
        for (int j = 1; j <= n; j++) {
            if (pattern[j - 1] == '*') {
                dp[0][j] = dp[0][j - 2];
            }
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (pattern[j - 1] == '.' || pattern[j - 1] == text[i - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (pattern[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 2];
                    if (pattern[j - 2] == '.' || pattern[j - 2] == text[i - 1]) {
                        dp[i][j] = dp[i][j] || dp[i - 1][j];
                    }
                }
            }
        }
        return dp[m][n];
    }
};
