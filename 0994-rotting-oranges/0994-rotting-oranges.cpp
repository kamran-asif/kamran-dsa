
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
         queue<pair<int,int>> q;
        int r=grid.size();
        int c=grid[0].size();
        vector<vector<int>> directions = {{0,1},{1,0},{0,-1},{-1,0}};

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==2)
                    q.push({i,j});
            }
        }

        int time=0;

        while(!q.empty()){
            int l=q.size();
            time++;
            while(l--){
                auto curr= q.front();
                q.pop();
                int x= curr.first;
                int y= curr.second;
                for(auto direction:directions){
                    int new_x= x+ direction[0];
                    int new_y= y+ direction[1];
                    if(new_x>=0 && new_x < r && new_y>=0 && new_y < c && grid[new_x][new_y]==1){
                        grid[new_x][new_y]=2;
                        q.push({new_x,new_y});
                    }

                }

            }
        }
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==1)
                    return -1;
            }
        }
        return max(0, time-1);
    }
};