class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
  
        vector<int> array;
        int remainder = grid[0][0]%x;

        //step-1: Insert array elements
        for(int i=0;i<grid.size();++i){
            for(int j=0;j<grid[0].size();++j){
                if(grid[i][j]%x != remainder)
                    return -1;//impossible to make Uni-Value Grid
                array.push_back(grid[i][j]);
            }
        }
        //step-2: sort 1D array
        sort(array.begin(),array.end());
        int n = array.size();
        int median = n/2;
        
        //step-3: count steps required
        int steps = 0;
        for(int i=0;i<n;++i)
            steps += abs(array[i]-array[median])/x;

        return steps;
    }      
    
};