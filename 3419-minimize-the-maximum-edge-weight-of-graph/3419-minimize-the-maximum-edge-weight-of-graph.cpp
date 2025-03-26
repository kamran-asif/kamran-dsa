class Solution {
public:
   
    bool canReachAll(int n, const vector<vector<int>>& edges, int M) {
        // build reverse graph using only edges with weight <= M
        vector<vector<int>> revGraph(n);
        for (const auto &edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            if (w <= M) {
                // reverse edge: from v to u
                revGraph[v].push_back(u);
            }
        }
        
        // perform BFS from node 0 in the reversed graph
        vector<bool> visited(n, false);
        queue<int> q;
        visited[0] = true;
        q.push(0);
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (int nxt : revGraph[cur]) {
                if (!visited[nxt]) {
                    visited[nxt] = true;
                    q.push(nxt);
                }
            }
        }
        
        // check if all nodes are visited
        for (bool v : visited) {
            if (!v) return false;
        }
        return true;
    }
    
    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        // note: the threshold condition is automatically met if we can choose
        // a rooted tree (a spanning tree with each node except 0 having exactly 1 outgoing edge)
        // because 1 <= threshold
        
        // find maximum edge weight among all edges
        int lo = 1, hi = 0;
        for (const auto &edge : edges) {
            hi = max(hi, edge[2]);
        }
        
        int ans = -1;
        // binary search over possible maximum allowed edge weight
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (canReachAll(n, edges, mid)) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ans;
    }
};
