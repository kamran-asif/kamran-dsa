class Solution {
public:
    vector<vector<int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}}; // directions ke liye
    
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size(); 
        int n = maze[0].size();
        queue<pair<int, int>> que; // bfs ke liye queue use karenge
        que.push({entrance[0], entrance[1]}); // entrance ko queue mein daalo
        maze[entrance[0]][entrance[1]] = '+'; // entrance ko visited mark kr dya
        
        int steps = 0; 

        // bfs 
        while (!que.empty()) {
            int N = que.size(); // current level ke kitne nodes process krne hain
            steps++;
            while (N--) {
                auto temp = que.front();
                que.pop();
                int i = temp.first; // current cell ka row index
                int j = temp.second; // current cell ka column index

                // 4 neighbors explore karo
                for (auto& dir : directions) {
                    int new_i = i + dir[0]; // naya row index
                    int new_j = j + dir[1]; // naya column index

                    
                    if (new_i >= 0 && new_i < m && new_j >= 0 && new_j < n && maze[new_i][new_j] != '+') {
                        // agar exit mila (boundary par ho) aur entrance nahi ho toh return kar do
                        if (new_i == 0 || new_i == m - 1 || new_j == 0 || new_j == n - 1) {
                            return steps; // steps waps karo
                        }
                        // nhi toh queue mein dalo aur visited mark karo
                        maze[new_i][new_j] = '+';
                        que.push({new_i, new_j});
                    }
                }
            }
        }
        return -1; 
    }
};
