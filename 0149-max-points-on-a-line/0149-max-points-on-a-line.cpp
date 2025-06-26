class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n < 3) return n;
        int result = 0;
        for (int i = 0; i < n; i++) {
            unordered_map<long double,int> slopecnt;
            int samepoints = 1;
            int verticals = 0;
            for (int j = i + 1; j < n; j++) {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];
                if (dx == 0 && dy == 0) {
                    samepoints++;
                } else if (dx == 0) {
                    verticals++;
                } else {
                    long double slope = (long double)dy / dx;
                    slopecnt[slope]++;
                }
            }
            int currentmax = verticals;
            for (auto &p : slopecnt) {
                currentmax = max(currentmax, p.second);
            }
            result = max(result, currentmax + samepoints);
        }
        return result;
    }
};
