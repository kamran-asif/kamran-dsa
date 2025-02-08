class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j) {
        // Agar grid ke bahar chale gaye ya 0 pe aaye toh wapas jao
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) {
            return;
        }
        // Cell ko visited mark karte hain (0 kar dete hain)
        grid[i][j] = 0;

        // 4 directions mein dfs call karte hain
        dfs(grid, i, j + 1); 
        dfs(grid, i, j - 1); 
        dfs(grid, i - 1, j); 
        dfs(grid, i + 1, j); 
    }

    int n, m; 
    int numEnclaves(vector<vector<int>>& grid) {
        m = grid.size();     
        n = grid[0].size();  

    //dfs
        for (int row = 0; row < m; row++) {
            // 1st column
            if (grid[row][0] == 1) {
                dfs(grid, row, 0);
            }
            // lst column
            if (grid[row][n - 1] == 1) {
                dfs(grid, row, n - 1);
            }
        }

    //dfs 
        for (int col = 0; col < n; col++) {
            // 1st row
            if (grid[0][col] == 1) {
                dfs(grid, 0, col);
            }
            //lst row
            if (grid[m - 1][col] == 1) {
                dfs(grid, m - 1, col);
            }
        }

        int count = 0;
        // ab un cells ko count karte hain jo abhi bhi 1 hain
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    count++;
                }
            }
        }
        return count;
    }
};
