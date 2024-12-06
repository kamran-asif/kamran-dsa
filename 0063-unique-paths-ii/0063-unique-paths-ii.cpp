class Solution {
public:
int mazeObstaclesUtil(int n, int m, vector<vector<int>> &maze, vector<vector<int>> &dp) {
    //traversing the grid
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
              //base 
               if (maze[i][j] == 1) {
                    dp[i][j] = 0;
                    continue;
              }
              if(i==0&&j==0){
                dp[i][j]=1;//agr hm starting point pr hai to
                continue;
              }
              int up=0;
              int left=0;
              if(i>0)
              up=dp[i-1][j];
              if(j>0)
              left=dp[i][j-1];
              dp[i][j]=up+left;
        }
       } 
 return dp[n-1][m-1];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
      int n=obstacleGrid.size();
      int m=obstacleGrid[0].size();
      vector<vector<int>>dp(n,vector<int>(m,-1));
       return mazeObstaclesUtil(n, m, obstacleGrid, dp);
    }
      

    
  
};