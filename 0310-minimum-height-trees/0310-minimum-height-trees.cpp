class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        
        // if only one node, it's the only MHT
        if (n == 1) return {0};
        
        //degree array
        vector<vector<int>> graph(n);
        vector<int> degree(n, 0);
        
        //grph
        for (auto &e : edges) {
            int a = e[0], b = e[1];
            graph[a].push_back(b);
            graph[b].push_back(a);
            degree[a]++;
            degree[b]++;
        }
        
        // cllct initial leaves (nodes with degree 1)
        queue<int> leaves;
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1) leaves.push(i);
        }
        
        int remainingNodes = n;
        
        // trim leaves until ≤ 2 nodes remain
        while (remainingNodes > 2) {
            int leavesCount = leaves.size();
            remainingNodes -= leavesCount;
            
            for (int i = 0; i < leavesCount; i++) {
                int leaf = leaves.front();
                leaves.pop();
                
                // reduce neighbor degree, add new leaves
                for (int neighbor : graph[leaf]) {
                    degree[neighbor]--;
                    if (degree[neighbor] == 1) leaves.push(neighbor);
                }
            }
        }
        
        // remaining nodes are MHT roots
        vector<int> result;
        while (!leaves.empty()) {
            result.push_back(leaves.front());
            leaves.pop();
        }
        return result;
    }
};
