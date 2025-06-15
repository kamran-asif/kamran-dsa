class Solution {
public:
    double knightProbability(int n, int k, int row, int column) {
       vector<vector<vector<double>>>dp(k+1,vector<vector<double>>(n,vector<double>(n,0)));
       dp[0][row][column]=1.0;
      vector<pair<int,int>>directions={{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}};

    for(int move=0;move<k;move++){
    for(int i=0;i<n;i++){
     for(int j=0;j<n;j++){
        if(dp[move][i][j]>0){
            for(auto dir:directions){
                int ni=i+dir.first;
                int nj=j+dir.second;
                if(ni>=0&&ni<n&&nj>=0&&nj<n){
                    dp[move+1][ni][nj]+=dp[move][i][j]/8.0;
                }

                            }
        }
     }
    }
    }
    double result =0.0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            result+=dp[k][i][j];
        }
    }
    return result;
}
};