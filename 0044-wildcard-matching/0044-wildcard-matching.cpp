class Solution {
public://bottom up tough h iska dhyan s
    bool isMatch(string s, string p) {
       /*  int m = s.length(), n = p.length();  
    
    // Create a DP table with (m+1) x (n+1)  
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));  
    
    // Empty string and empty pattern match  
    dp[0][0] = true;  
    
    // Fill the first row for patterns like "*", "**", "***", etc.  
    for (int j = 1; j <= n; j++) {  
        if (p[j - 1] == '*') {  
            dp[0][j] = dp[0][j - 1];  
        }  
    }  
    
    // Fill the DP table  
    for (int i = 1; i <= m; i++) {  
        for (int j = 1; j <= n; j++) {  
            if (p[j - 1] == '*') {  
                // '*' can match zero or more characters  
                dp[i][j] = dp[i][j - 1] || dp[i - 1][j];  
            } else if (p[j - 1] == '?' || s[i - 1] == p[j - 1]) {  
                // Match single character or '?'  
                dp[i][j] = dp[i - 1][j - 1];  
            }  
        }  
    }  
    
    return dp[m][n];  
*/
    //bottom up
        vector<char> pattern;
        
        // remove consecutive '*'
        bool isFirst = true;
        for (char ch : p) {
            if (ch == '*') {
                if (isFirst) {
                    pattern.push_back(ch);
                    isFirst = false;
                }
            } else {
                pattern.push_back(ch);
                isFirst = true;
            }
        }

        int m = s.size(), n = pattern.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        
        dp[0][0] = true;
        if (!pattern.empty() && pattern[0] == '*') {
            dp[0][1] = true;
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (pattern[j - 1] == '?' || s[i - 1] == pattern[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (pattern[j - 1] == '*') {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                }
            }
        }
        return dp[m][n];
    }

    bool isMatchRecursive(string s, string p) {
        return isMatchRecursiveUtil(s, p, 0, 0);
    }

private:
    bool isMatchRecursiveUtil(const string& text, const string& pattern, int pos1, int pos2) {
        if (pos2 == pattern.size()) return pos1 == text.size();

        if (pattern[pos2] != '*') {
            if (pos1 < text.size() && (text[pos1] == pattern[pos2] || pattern[pos2] == '?')) {
                return isMatchRecursiveUtil(text, pattern, pos1 + 1, pos2 + 1);
            }
            return false;
        } else {
            while (pos2 < pattern.size() - 1 && pattern[pos2 + 1] == '*') pos2++;

            pos1--;
            while (pos1 < text.size()) {
                if (isMatchRecursiveUtil(text, pattern, pos1 + 1, pos2 + 1)) return true;
                pos1++;
            }
            return false;
        }
    }
};
