class Solution {
public:
    static bool comparator(vector<int>& val1, vector<int>& val2) {
        return val1[1] < val2[1]; // Sort intervals by their end times
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0; // edge case no intervals
        
        // sort intervals by their end times
        sort(intervals.begin(), intervals.end(), comparator);

        int cnt = 1; //cnt of non-overlapping intervals
        int lastEndTime = intervals[0][1]; // initialize with the end time of the first interval

        // traverse the sorted intervals
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] >= lastEndTime) { 
                // if the current interval does not overlap
                cnt++;
                lastEndTime = intervals[i][1]; // update the last end time
            }
        }

        return intervals.size() - cnt; // overlapping intervals = total - non-overlapping
    }
};
