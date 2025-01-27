class Solution {
    private:
    void bfs(int i,int j,vector<vector<int>>&vis,vector<vector<char>>&grid){
        if(i<0||j<0||i>=grid.size()||j>=grid[0].size()||grid[i][j]!='1')
        return ;
        if(grid[i][j]==-1){
            
            return ;
        }
        grid[i][j] ='$';
         
        bfs(i + 1, j, vis, grid); // Down
    bfs(i - 1, j, vis, grid); // Up
    bfs(i, j + 1, vis, grid); // Right
    bfs(i, j - 1, vis, grid); // Left
}
    
public:
    int numIslands(vector<vector<char>>& grid) {
     
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    bfs(i,j,vis,grid);
                    cnt++;
                }
            }
        }
    return cnt;
    }
};