class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
     vector<int>dp=triangle[n-1];
     for (int i = n - 2; i >= 0; i--) { // Start from the second-to-last row
            for (int j = 0; j <= i; j++) { // Process only up to the current row's length
                dp[j] = min(dp[j], dp[j + 1]) + triangle[i][j];
            }
        }

        
       return dp[0];
    }
};