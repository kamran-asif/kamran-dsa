class Solution {
public:
    typedef pair<int, pair<int, int>> P;
    vector<vector<int>> directions{
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}, 
        {-1, -1}, {-1, 1}, {1, -1}, {1, 1}
    };

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        // edge case when ceel is blocked
        if (grid[0][0] != 0 || grid[n - 1][m - 1] != 0)
            return -1;

        // lambda function for checking valid indices
        auto isSafe = [&](int x, int y) {
            return x >= 0 && y >= 0 && x < n && y < m;
        };

        // dstance matrix to track shortest path
        vector<vector<int>> result(n, vector<int>(m, INT_MAX));

        // min heap (priority queue) for dijkstra's algorithm
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({1, {0, 0}}); // dstance, (row, col)
        result[0][0] = 1;

        while (!pq.empty()) {
            int d = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();

            // if we reach the bottom-right corner
            if (x == n - 1 && y == m - 1) 
                return d;

            for (auto& dir : directions) {
                int newX = x + dir[0];
                int newY = y + dir[1];

                if (isSafe(newX, newY) && grid[newX][newY] == 0 && d + 1 < result[newX][newY]) {
                    pq.push({d + 1, {newX, newY}});
                    result[newX][newY] = d + 1;
                }
            }
        }

        return -1;
    }
};
