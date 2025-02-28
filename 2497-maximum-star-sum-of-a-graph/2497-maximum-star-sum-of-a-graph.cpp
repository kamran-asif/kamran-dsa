class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int n = vals.size();
        
        // Step 1: Construct adjacency list
        vector<vector<int>> graph(n);
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        int maxSum = INT_MIN;

        // Step 2: Iterate over each node as the center of the star
        for (int center = 0; center < n; ++center) {
            // Use a max-heap to store the k largest positive neighbor values
            priority_queue<int> pq;
            
            for (int neighbor : graph[center]) {
                if (vals[neighbor] > 0) {
                    pq.push(vals[neighbor]); // Only push positive values
                }
            }

            // Compute the star sum with at most k neighbors
            int starSum = vals[center];
            int count = 0;

            while (!pq.empty() && count < k) {
                starSum += pq.top();
                pq.pop();
                count++;
            }

            // Update the maximum star sum found so far
            maxSum = max(maxSum, starSum);
        }

        return maxSum;
    }
};
