class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newintervals) {
     vector<vector<int>> res;
      int n = intervals.size();
      int i=0;
     //left most part
     while(i<n&&intervals[i][1]<newintervals[0]){
            res.push_back(intervals[i]);
            i=i+1;
     } 
     //merge  
     while(i<n&&intervals[i][0]<=newintervals[1]){
        newintervals[0]=min(newintervals[0],intervals[i][0]);
        newintervals[1]=max(newintervals[1],intervals[i][1]);
        i=i+1;
     }
     res.push_back(newintervals);
//left part
     while(i<n){
        res.push_back(intervals[i]);
        i=i+1;
     }
     return res;
    }
};