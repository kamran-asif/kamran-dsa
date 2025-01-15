class Solution {
public:
static bool comparator(vector<int>val1,vector<int>val2){
    return val1[1]<val2[1];
}
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
     sort(intervals.begin(), intervals.end(), comparator);
     int cnt=1;
     int lastendtime=intervals[0][1];
     int n=intervals.size();
     for(int i=1;i<n;i++){
          if(intervals[i][0]>=lastendtime)
          cnt=cnt+1;
          lastendtime=intervals[i][1];
     }  
     return n-cnt;
    }
};