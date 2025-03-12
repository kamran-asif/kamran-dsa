/*class Solution {
public:// o(n+m)soln
    int countNegatives(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
       int left=m-1,right=0;
       int cnt=0;
       int mid=left+(right-left)/2;
       while(left>=0&&right<n){
         if(grid[left][right]<0){
          cnt+=(n-right);
         left--;
         }else{
          right++;
         }
       }
return cnt;
    }
};*/
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int totalnegindx = 0; 
        for (int i = 0; i < n; i++) {
            int left = 0, right = m - 1, firstnegindx = m;

            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (grid[i][mid] < 0) {
                    firstnegindx = mid;
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            totalnegindx += (m - firstnegindx);
        }

        return totalnegindx;
    }
};

